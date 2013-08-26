using System;
using NUnit.Framework;

namespace Prometheus
{
	[TestFixture]
	public class RuleNodeTest
	{
		[Test]
		public void ConstructionTest()
		{
			string name = "Ethan & Jordan RULE"; // pun intended
			RuleNode rn = new RuleNode(name);
			Assert.AreEqual(name, rn.Name);
		}

		[Test]
		public void DefaultConstructionTest()
		{
			RuleNode rn = new RuleNode();
			Assert.AreEqual("Default Rule", rn.Name);
		}
	}
}

