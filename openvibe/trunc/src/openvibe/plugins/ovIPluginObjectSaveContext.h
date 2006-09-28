#ifndef __OpenViBE_Plugins_IPluginObjectSaveContext_H__
#define __OpenViBE_Plugins_IPluginObjectSaveContext_H__

#include "../ov_base.h"
#include "ovIPluginObjectContext.h"

namespace OpenViBE
{
	namespace Plugins
	{
		/**
		 * \class IPluginObjectSaveContext
		 * \author Yann Renard (INRIA/IRISA)
		 * \date 2006-07-07
		 * \brief Plugin objects save interface
		 *
		 * This context is given to each plugin object that
		 * has to be saved from something to allow it to
		 * be saved.
		 */
		class OV_API IPluginObjectSaveContext : virtual public OpenViBE::Plugins::IPluginObjectContext
		{
		public:

			// TODO

			_IsDerivedFromClass_(OpenViBE::Plugins::IPluginObjectContext, OV_ClassId_Plugins_PluginObjectSaveContext)

		};
	};
};

#endif // __OpenViBE_Plugins_IPluginObjectSaveContext_H__
