using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prometheus.Model
{
    class Database
    {
        Dictionary<string, List<Node>> nodes;
        public Database()
        {
            nodes = new Dictionary<string, List<Node>>();
        }

        public Dictionary<string, List<Node>> Nodes
        {
            get { return nodes; }
        }

        public void Insert(Node node)
        {
            var list = new List<Node>();
            if (Nodes.TryGetValue(node.Parent.Name, out list))
            {
                list.Add(node);
            }
            else
            {
                list.Add(node);
            }
            Nodes.Add(node.Parent.Name, list);
        }

        public bool Remove(Node node)
        {
            
        }

        public List<Node> ParentQuery(string query)
        {
            var nodes = new List<Node>();

            

            return nodes;
        }
    }
}
