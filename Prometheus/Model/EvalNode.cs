using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Prometheus.Model
{
    class EvalNode : Node
    {
        string eval;

        public EvalNode(string name, Node parent) : base(name, parent)
		{
		}

        public string Eval
        {
            get { return eval; }
            set { eval = value; }
        }

        public bool isNumber()
        {
            Regex regex = new Regex(@"^[0-9]*[.]?[0-9]*$");
            return regex.IsMatch(Eval);
        }
    }
}
