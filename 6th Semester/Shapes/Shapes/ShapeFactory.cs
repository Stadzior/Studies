using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    class ShapeFactory
    {
        private Random _randomGenerator;

        public ShapeFactory()
        {
            _randomGenerator = new Random();
        }

        public IShape CreateShape(Type shapeType)
        {
            return (IShape)Activator.CreateInstance(shapeType, _randomGenerator.Next(1, 10), _randomGenerator.Next(1, 10));
        }
    }
}
