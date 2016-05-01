using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    public interface IShape
    {
        double Area { get; set; }
        double Circuit { get; set; }
        int FactorA { get; set; }
        int FactorB { get; set; }
        void CalculateArea(int a,int b);
        void CalculateCircuit(int a, int b);        
    }
}
