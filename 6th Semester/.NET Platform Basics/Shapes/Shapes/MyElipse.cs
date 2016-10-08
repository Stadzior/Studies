using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    class MyElipse : IShape
    {
        public double Area { get; set; }
        public double Circuit { get; set; }
        public int FactorA { get; set; }
        public int FactorB { get; set; }

        public MyElipse(int a,int b)
        {
            CalculateArea(a, b);
            CalculateCircuit(a, b);
            FactorA = a;
            FactorB = b;
        }

        public void CalculateArea(int a, int b)
        {
            Area = Math.Round(Math.PI * a * b,3);
        }

        public void CalculateCircuit(int a, int b)
        {
            Circuit = Math.Round(Math.PI * ((3.0/2.0)*(a+b) - Math.Sqrt(a*b)), 3);
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("Elipsa o polu: ");
            stringBuilder.Append(Area.ToString());
            stringBuilder.Append(" i obwodzie: ");
            stringBuilder.Append(Circuit.ToString());
            return stringBuilder.ToString();
        }
    }
}
