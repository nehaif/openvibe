#ifndef __SimpleVisualisationPlugin_CVoxelView_H__
#define __SimpleVisualisationPlugin_CVoxelView_H__

#include "../ovp_defines.h"

#include <openvibe/ov_all.h>
#include <openvibe-toolkit/ovtk_all.h>

#include <glade/glade.h>
#include <gtk/gtk.h>

#include "../ovpCVoxelDisplay.h"

#include <vector>
#include <string>

namespace OpenViBEPlugins
{
	namespace SimpleVisualisation
	{
		/**
		 * This class contains everything necessary to setup a GTK window and display
		 * a voxel visualiser
		 */
		class CVoxelView : public OpenViBEPlugins::SimpleVisualisation::IStreamDisplayDrawable
		{
		public:
			/**
			 * \brief Constructor
			 * \param rVoxelDisplay Parent plugin
			 */
			CVoxelView(
				CVoxelDisplay& rVoxelDisplay);

			/**
			 * \brief Destructor
			 */
			virtual ~CVoxelView();

			/** \name IStreamDisplayDrawable implementation */
			//@{

			/**
			 * \brief Initialize widgets.
			 * \remark Called automatically by spectrum database when first buffer is received
			 * \return True if initialization was successful, false otherwise
			 */
			virtual OpenViBE::boolean init(void);

			/**
			 * \brief Invalidate window contents and have it redraw itself.
			 * \return True if redraw was successful, false otherwise
			 */
			virtual OpenViBE::boolean redraw(void);

			//@}

			/**
			 * \brief Get toolbar pointer (if any)
			 * \param [out] pToolbarWidget Pointer to toolbar widget
			 */
			void getToolbar(
				GtkWidget*& pToolbarWidget);
			/**
			 * Returns name of viewport currently used
			 */
			//EVoxelViewport getCurrentViewport(void);
			/**
			 * Sets current viewport.
			 * \param eViewport Display mode to set.
			 */
			//void setCurrentViewport(
				//EVoxelViewport eViewport);

			void setVoxelObjectCB(GtkWidget* pWidget);
			void toggleColorModificationCB(OpenViBE::boolean bModifyColor);
			void toggleTransparencyModificationCB(OpenViBE::boolean bModifyTransparency);
			void toggleSizeModificationCB(OpenViBE::boolean bModifySize);
			void setMinVoxelScaleFactorCB(::GtkSpinButton* pWidget);
			void setMaxVoxelScaleFactorCB(::GtkSpinButton* pWidget);
			void setVoxelDisplayThresholdCB(OpenViBE::float64 f64Threshold);
			void setSkullOpacityCB(OpenViBE::float64 f64Delay);
			void setPausedCB(OpenViBE::boolean bPaused);
			void repositionCameraCB();

		private:
			CVoxelDisplay& m_rVoxelDisplay;

			::GladeXML* m_pGladeInterface;

			//! View radio buttons
			::GtkRadioToolButton* m_pCubeButton;
			::GtkRadioToolButton* m_pSphereButton;
		};
	}
}

#endif // __SimpleVisualisationPlugin_CVoxelView_H__
