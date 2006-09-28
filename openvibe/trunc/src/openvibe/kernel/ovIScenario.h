#ifndef __OpenViBE_Kernel_IScenario_H__
#define __OpenViBE_Kernel_IScenario_H__

#include "ovIKernelObject.h"

namespace OpenViBE
{
	namespace Kernel
	{
		class IBox;
		class ILink;

		/**
		 * \class IScenario
		 * \author Yann Renard (IRISA/INRIA)
		 * \date 2006-08-16
		 * \brief A static žOpenViBEž scenario
		 *
		 * This class is a static scenario description.
		 * It is used to load/save/modify an žOpenViBEž
		 * box/connection collection...
		 *
		 * \todo Add meta information for this scenario
		 */
		class IScenario : virtual public OpenViBE::Kernel::IKernelObject
		{
		public:

			class IBoxEnum
			{
			public:
				virtual ~IBoxEnum(void) { }
				virtual OpenViBE::boolean callback(
					const OpenViBE::Kernel::IScenario& rScenario,
					const OpenViBE::Kernel::IBox& rBox)=0;
			};

			class ILinkEnum
			{
			public:
				virtual ~ILinkEnum(void) { }
				virtual OpenViBE::boolean callback(
					const OpenViBE::Kernel::IScenario& rScenario,
					const OpenViBE::Kernel::ILink& rLink)=0;
			};

			/** \name Input / Output from files */
			//@{

			/**
			 * \brief Loads a scenario from a file
			 * \param sFileName [in] : The file to load the scenario from
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean load(
				const OpenViBE::CString& sFileName)=0;
			/**
			 * \brief Saves a scenario to a file
			 * \param sFileName [in] : The file to save the scenario to
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean save(
				const OpenViBE::CString& sFileName) const=0;

			//@{
			/** \name Box management */
			//@{

			/**
			 * \brief Enumerates all the boxes of this scenario
			 * \param rCallback [in] : The user callback
			 *        to use for each found box in the scenario
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean enumerateBoxes(
				OpenViBE::Kernel::IScenario::IBoxEnum& rCallback) const=0;
			/**
			 * \brief Gets the details for a specific box
			 * \param rBoxIdentifier [in] : The identifier
			 *        of the box which details should be
			 *        sent.
			 * \return The box details
			 */
			virtual const OpenViBE::Kernel::IBox* getBoxDetails(
				const OpenViBE::CIdentifier& rBoxIdentifier) const=0;
			/// \copydoc getBoxDetails(const OpenViBE::CIdentifier&)const
			virtual OpenViBE::Kernel::IBox* getBoxDetails(
				const OpenViBE::CIdentifier& rBoxIdentifier)=0;
			/**
			 * \brief Adds a new box in the scenario
			 * \param rBoxAlgorithmClassIdentifier [in] : The
			 *        class identifier of the algorithm for
			 *        this box
			 * \param rBoxBehaviorClassIdentifier [in] : The
			 *        class identifier of the behavior for
			 *        this box
			 * \param rBoxIdentifier [out] : The identifier of
			 *        the created box
			 * \return \e true in case of success.
			 * \return \e false in case of error. In such case,
			 *         \c rBoxIdentifier remains unchanged.
			 */
			virtual OpenViBE::boolean addBox(
				const OpenViBE::CIdentifier& rBoxAlgorithmClassIdentifier,
				const OpenViBE::CIdentifier& rBoxBehaviorClassIdentifier,
				OpenViBE::CIdentifier& rBoxIdentifier)=0;
			/**
			 * \brief Removes a box of the scenario
			 * \param rBoxIdentifier [in] : The box identifier
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 * \note Each link related to this box is also removed
			 */
			virtual OpenViBE::boolean removeBox(
				const OpenViBE::CIdentifier& rBoxIdentifier)=0;

			//@}
			/** \name Connection management */
			//@{

			/**
			 * \brief Enumerates all the links of this scenario
			 * \param rCallback [in] : The user callback
			 *        to use for each found link in the scenario
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean enumerateLinks(
				OpenViBE::Kernel::IScenario::ILinkEnum& rCallback) const=0;
			/**
			 * \brief Enumerates the links of this scenario starting from a given box
			 * \param rCallback [in] : The user callback
			 *        to use for each found link in the scenario
			 * \param rBoxIdentifier [in] : The box identifier
			 *        which the link should start from
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean enumerateLinksFromBox(
				OpenViBE::Kernel::IScenario::ILinkEnum& rCallback,
				const OpenViBE::CIdentifier& rBoxIdentifier) const=0;
			/**
			 * \brief Enumerates the links of this scenario ending to a given box
			 * \param rCallback [in] : The user callback
			 *        to use for each found link in the scenario
			 * \param rBoxIdentifier [in] : The box identifier
			 *        which the link should end to
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean enumerateLinksToBox(
				OpenViBE::Kernel::IScenario::ILinkEnum& rCallback,
				const OpenViBE::CIdentifier& rBoxIdentifier) const=0;
			/**
			 * \brief Gets the details for a specific link
			 * \param rLinkIdentifier [in] : The identifier
			 *        of the link which details should be
			 *        sent.
			 * \return The link details
			 */
			virtual const OpenViBE::Kernel::ILink* getLinkDetails(
				const OpenViBE::CIdentifier& rLinkIdentifier) const=0;
			/// \copydoc getLinkDetails(const OpenViBE::CIdentifier&)const
			virtual OpenViBE::Kernel::ILink* getLinkDetails(
				const OpenViBE::CIdentifier& rLinkIdentifier)=0;
			/**
			 * \brief Creates a connection between two boxes
			 * \param rSourceBoxIdentifier [in] : The source
			 *        box identifier
			 * \param ui32SourceBoxOutputIndex [in] : The output
			 *        index for the given source box
			 * \param rTargetBoxIdentifier [in] : The target
			 *        box identifier
			 * \param ui32TargetBoxInputIndex [in] : The input
			 *        index for the given target box
			 * \param rLinkIdentifier [out] : The created link
			 *        identifier.
			 * \return \e true in case of success.
			 * \return \e false in case of error. In such case,
			 *         rLinkIdentifier remains unchanged.
			 */
			virtual OpenViBE::boolean connect(
				const OpenViBE::CIdentifier& rSourceBoxIdentifier,
				const OpenViBE::uint32 ui32SourceBoxOutputIndex,
				const OpenViBE::CIdentifier& rTargetBoxIdentifier,
				const OpenViBE::uint32 ui32TargetBoxInputIndex,
				OpenViBE::CIdentifier& rLinkIdentifier)=0;
			/**
			 * \brief Deletes a connection between two boxes
			 * \param rSourceBoxIdentifier [in] : The source
			 *        box identifier
			 * \param ui32SourceBoxOutputIndex [in] : The output
			 *        index for the given source box
			 * \param rTargetBoxIdentifier [in] : The target
			 *        box identifier
			 * \param ui32TargetBoxInputIndex [in] : The input
			 *        index for the given target box
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean disconnect(
				const OpenViBE::CIdentifier& rSourceBoxIdentifier,
				const OpenViBE::uint32 ui32SourceBoxOutputIndex,
				const OpenViBE::CIdentifier& rTargetBoxIdentifier,
				const OpenViBE::uint32 ui32TargetBoxInputIndex)=0;
			/**
			 * \brief Deletes a connection between two boxes
			 * \param rLinkIdentifier [out] : The identifier
			 *        for the link to be deleted
			 * \return \e true in case of success.
			 * \return \e false in case of error.
			 */
			virtual OpenViBE::boolean disconnect(
				const OpenViBE::CIdentifier& rLinkIdentifier)=0;

			//@}

			_IsDerivedFromClass_(OpenViBE::Kernel::IKernelObject, OV_ClassId_Kernel_Scenario)
		};
	};
};

#endif // __OpenViBE_Kernel_IScenario_H__
