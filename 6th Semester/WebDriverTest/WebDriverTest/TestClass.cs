using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Firefox;
using OpenQA.Selenium.Remote;
using Shouldly;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WebDriverTest
{
    [TestFixture]
    public class TestClass
    {
        IWebDriver driver;

        [OneTimeSetUp]
        public void SetUp()
        {
            driver = new FirefoxDriver();
        }

        [Test]
        public void DrinkingBeer_ShouldBeAllowed_WhenAllTestsPass()
        {
            // Arrange
            driver.Navigate().GoToUrl("http://www.pracuj.pl");
            IWebElement keywords = driver.FindElement(By.Id("keywords"));
            IWebElement location = driver.FindElement(By.Id("location"));
            IWebElement searchButton = driver.FindElement(By.Id("searchBtn"));



            // Act
            keywords.SendKeys("C++");
            location.SendKeys("Łódź");
            searchButton.Click();
            var counter = driver.FindElement(By.CssSelector("p.offer__search_results_title > span")).Text;
            var offers = driver.FindElement(By.Id("mainOfferList")).FindElements(By.ClassName("offer__list_item"));
            // Assert
            
            offers.Count.ShouldBe(int.Parse(counter));

        }

        [OneTimeTearDown]
        public void TearDown()
        {
            driver.Close();
        }
    }
}
