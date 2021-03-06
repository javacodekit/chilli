#pragma once
#include "..\Extension\ExtensionImp.h"
#include <log4cplus\logger.h>


namespace chilli{
namespace Group {

	class GroupImp :public Extension::ExtensionImp {
	public:
		GroupImp(model::ProcessModule * model, const std::string &ext, const std::string &smFileName);
		virtual ~GroupImp();

		//inherit from SendInterface
		virtual void fireSend(const std::string &strContent, const void * param) override;

	protected:
		void processSend(const std::string &strContent, const void * param, bool & bHandled);

	};
	typedef std::shared_ptr<GroupImp>  GroupImpPtr;
}
}