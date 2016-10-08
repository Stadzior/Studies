using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceLibrary.ServiceLibraryClient proxy = new ServiceLibrary.ServiceLibraryClient();

            int idUser = 0;

            List<int> listOfBooksIdsToBorrow = new List<int>() { 0, 1, 2};

            foreach(int idBook in listOfBooksIdsToBorrow)
            {
                try
                {
                    proxy.BorrowBook(idUser, idBook);
                    Console.WriteLine("User no." + idUser.ToString() + " borrowed " + proxy.GetBookInfo(idBook).Author + " " + proxy.GetBookInfo(idBook).Title);
                    Console.WriteLine();                                 
                } 
                catch(FaultException fault)
                {
                    Console.WriteLine(fault.Message);
                }
            }

            Console.WriteLine("List of books borrowed by user no." + idUser);

            foreach (var book in proxy.GetBorrowedBooksByUser(idUser))
            {
                Console.WriteLine(book.Info.Title);
            }

            Console.ReadKey();
        }
    }
}
