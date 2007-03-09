#ifndef __OpenViBEKernel_Kernel_CObjectFactory_H__
#define __OpenViBEKernel_Kernel_CObjectFactory_H__

#include "ovkTKernelObject.h"

#include <vector>

namespace OpenViBE
{
	namespace Kernel
	{
		class CObjectFactory : virtual public OpenViBE::Kernel::TKernelObject<OpenViBE::Kernel::IObjectFactory>
		{
		public:

			CObjectFactory(const OpenViBE::Kernel::IKernelContext& rKernelContext);

			virtual OpenViBE::IObject* createObject(
				const OpenViBE::CIdentifier& rClassIdentifier);
			virtual OpenViBE::boolean releaseObject(
				OpenViBE::IObject* pObject);

			_IsDerivedFromClass_Final_(OpenViBE::Kernel::IObjectFactory, OVK_ClassId_Kernel_ObjectFactory)

		protected:

			std::vector<OpenViBE::IObject*> m_oCreatedObjects;
		};
	};
};

#endif // __OpenViBEKernel_Kernel_CObjectFactory_H__
