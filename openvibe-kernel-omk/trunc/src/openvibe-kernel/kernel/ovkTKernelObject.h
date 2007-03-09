#ifndef __OpenViBEKernel_Kernel_TKernelObject_H__
#define __OpenViBEKernel_Kernel_TKernelObject_H__

#include "../ovk_base.h"

#include <openvibe/ov_all.h>

namespace OpenViBE
{
	namespace Kernel
	{
		template <class T>
		class TKernelObject : virtual public T
		{
		public:

			TKernelObject(const OpenViBE::Kernel::IKernelContext& rKernelContext)
				:m_rKernelContext(rKernelContext)
			{
			}

			const OpenViBE::Kernel::IKernelContext& getKernelContext(void) const
			{
				return m_rKernelContext;
			}

			OpenViBE::Kernel::ILogManager& log(void) const
			{
				return m_rKernelContext.getLogManager();
			}

			_IsDerivedFromClass_(T, OVK_ClassId_Kernel_KernelObject)

		private:

			const OpenViBE::Kernel::IKernelContext& m_rKernelContext;

			// TKernelObject(void);
		};
	};
};

#endif // __OpenViBEKernel_Kernel_TKernelObject_H__
