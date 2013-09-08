using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prometheus.Model
{
    class Database
    {
        Dictionary<string, SortedSet<Node>> nodes;
        public Database()
        {
            nodes = new Dictionary<string, SortedSet<Node>>();
        }

        public Dictionary<string, SortedSet<Node>> Nodes
        {
            get { return nodes; }
        }

        public void Insert(Node node)
        {
            var list = new SortedSet<Node>();
            if (Nodes.TryGetValue(node.Parent.Name, out list))
                list.Add(node);
            else
                list.Add(node);
            Nodes.Add(node.Parent.Name, list);
        }

        public bool Remove(Node node)
        {
            var list = new SortedSet<Node>();
            if (Nodes.TryGetValue(node.Parent.Name, out list))
                if (list.Contains(node))
                    return list.Remove(node);
            return false;
        }


        /// <summary>
        /// Returns a list of nodes that have the same parent
        /// (will mostly be used in the model for generating tables)
        /// </summary>
        /// <param name="query"> parent string </param>
        /// <returns>
        /// Returns a list of nodes that have the same parent,
        /// If no nodes are avalible, will return a empty SortedSet
        /// </returns>
        public SortedSet<Node> ParentQuery(string query)
        {
            var list = new SortedSet<Node>();
            return Nodes.TryGetValue(query, out list) ? list : list;
        }
    }
}
