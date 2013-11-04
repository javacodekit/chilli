#pragma once
#ifndef _FSM_CONTEXT_HEADER_
#define _FSM_CONTEXT_HEADER_
#include "Context.h"
#include "libxml/tree.h"
#include <log4cplus/logger.h>


namespace fsm
{


	/// <summary>
	/// Interface for a component that may be used by the SCXML engines to
	/// evaluate the expressions within the SCXML document.
	/// 
	/// </summary>
	class Evaluator
	{

		/// <summary>
		/// Evaluate an expression.
		/// </summary>
		/// <param name="ctx"> variable context </param>
		/// <param name="expr"> expression </param>
		/// <returns> a result of the evaluation </returns>
		/// <exception cref="SCXMLExpressionException"> A malformed exception </exception>
	public:
		virtual std::string eval(Context *const ctx, const std::string &expr,unsigned int line) = 0;

		/// <summary>
		/// Evaluate a condition.
		/// Manifests as "cond" attributes of "transition" and "event" elements.
		/// </summary>
		/// <param name="ctx"> variable context </param>
		/// <param name="expr"> expression </param>
		/// <returns> true/false </returns>
		/// <exception cref="SCXMLExpressionException"> A malformed exception </exception>
		virtual bool evalCond(Context *const ctx, const std::string &expr,unsigned int line) = 0;

		/// <summary>
		/// Evaluate a location that returns a Node within an XML data tree.
		/// Manifests as "location" attributes of &lt;assign&gt; element.
		/// </summary>
		/// <param name="ctx"> variable context </param>
		/// <param name="expr"> expression </param>
		/// <returns> The location node. </returns>
		/// <exception cref="SCXMLExpressionException"> A malformed exception </exception>
		virtual xmlNodePtr evalLocation(Context *const ctx, const std::string &expr,unsigned int line) = 0;

		/// <summary>
		/// Create a new child context.
		/// </summary>
		/// <param name="parent"> parent context </param>
		/// <returns> new child context </returns>
		virtual Context * newContext(Context * const parent,log4cplus::Logger log) = 0;

	};

}

#endif // end context head