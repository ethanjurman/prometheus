using System;
using NUnit.Framework;

namespace Prometheus.Model
{
	[TestFixture]
	public class EvalNodeTest
	{
		[Test]
		public void numberCheckTest()
		{
			EvalNode node = new EvalNode("Test", null){Eval = "122.1"};
			Assert.IsTrue(node.isNumber());

			node.Eval = "122";
			Assert.IsTrue(node.isNumber());

			node.Eval = ".10";
			Assert.IsTrue(node.isNumber());

			node.Eval = "10.1234";
			Assert.IsTrue(node.isNumber());

			node.Eval = "100p";
			Assert.IsFalse(node.isNumber());

			node.Eval = "x100";
			Assert.IsFalse(node.isNumber());

			node.Eval = "ethan";
			Assert.IsFalse(node.isNumber());
		}
	}
}

