﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    class MyTriangle : IShape
    {
        public double Area { get; set; }
        public double Circuit { get; set; }
        public int FactorA { get; set; }
        public int FactorB { get; set; }

        public MyTriangle(int a, int b)
        {
            CalculateArea(a, b);
            CalculateCircuit(a, b);
            FactorA = a;
            FactorB = b;
        }

        public void CalculateArea(int a, int b)
        {
            Area = Math.Round((double)((a * b) / 2),3);
        }

        public void CalculateCircuit(int a, int b)
        {
            double armLength = Math.Round((double)(Math.Sqrt(a * a + b * b)),3);
            Circuit = a + 2 * armLength;
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("Trójkąt o polu: ");
            stringBuilder.Append(Area.ToString());
            stringBuilder.Append(" i obwodzie: ");
            stringBuilder.Append(Circuit.ToString());
            return stringBuilder.ToString();
        }

    }
}
