using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Prometheus.Model
{
    public class EvalNode : Node
    {
        string eval;

        public EvalNode(string name, Node parent, Database db) : base(name, parent, db)
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
