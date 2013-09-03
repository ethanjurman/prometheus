using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prometheus.Model
{
    class EvalNode : Node
    {
        string eval;

        public EvalNode(string name, ref Node parent) : base(name, ref parent)
		{
		}

        public string Eval
        {
            get { return eval; }
            set { eval = value; }
        }
    }
}
