using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Prometheus.Model;

namespace Prometheus.Controller
{
    class Controller : System.Collections.CollectionBase
    {
        public void Add(Event element)
        {
            List.Add(element);
        }

        public Event Pop()
        {
            var element = List[Count - 1];
            List.RemoveAt(Count - 1);
            //element.execute();
            return (Event)element;
        }
    }
}
