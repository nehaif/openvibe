#ifndef __OpenViBEToolkit_TSignalDecoder_H__
#define __OpenViBEToolkit_TSignalDecoder_H__

#ifdef TARGET_HAS_ThirdPartyOpenViBEPluginsGlobalDefines

#include "../../ovtk_base.h"

namespace OpenViBEToolkit
{
	template <class T>
	class TSignalDecoder : public T
	{
	protected:

		OpenViBE::Kernel::TParameterHandler < OpenViBE::IMatrix* > m_pOutputMatrix;
		OpenViBE::Kernel::TParameterHandler < OpenViBE::uint64 > m_pOutputSamplingRate;

	protected:

		OpenViBE::boolean initialize()
		{
			m_pCodec = &m_pBoxAlgorithm->getAlgorithmManager().getAlgorithm(m_pBoxAlgorithm->getAlgorithmManager().createAlgorithm(OVP_GD_ClassId_Algorithm_SignalStreamDecoder));
			m_pCodec->initialize();
			m_pOutputSamplingRate.initialize(m_pCodec->getOutputParameter(OVP_GD_Algorithm_SignalStreamDecoder_OutputParameterId_SamplingRate));
			m_pOutputMatrix.initialize(m_pCodec->getOutputParameter(OVP_GD_Algorithm_SignalStreamDecoder_OutputParameterId_Matrix));
			m_pInputMemoryBuffer.initialize(m_pCodec->getInputParameter(OVP_GD_Algorithm_SignalStreamDecoder_InputParameterId_MemoryBufferToDecode));

			return true;
		}

	public:

		using T::initialize;
		using T::m_pCodec;
		using T::m_pBoxAlgorithm;
		using T::m_pInputMemoryBuffer;

		OpenViBE::boolean uninitialize(void)
		{
			if(m_pBoxAlgorithm == NULL)
			{
				return false;
			}

			m_pOutputSamplingRate.uninitialize();
			m_pOutputMatrix.uninitialize();
			m_pInputMemoryBuffer.uninitialize();
			m_pCodec->uninitialize();
			m_pBoxAlgorithm->getAlgorithmManager().releaseAlgorithm(*m_pCodec);
			m_pBoxAlgorithm = NULL;

			return true;
		}

		OpenViBE::Kernel::TParameterHandler < OpenViBE::IMatrix* >& getOutputMatrix()
		{
			return m_pOutputMatrix;
		}

		OpenViBE::Kernel::TParameterHandler < OpenViBE::uint64 >& getOutputSamplingRate()
		{
			return m_pOutputSamplingRate;
		}

		virtual OpenViBE::boolean isHeaderReceived()
		{
			return m_pCodec->isOutputTriggerActive(OVP_GD_Algorithm_SignalStreamDecoder_OutputTriggerId_ReceivedHeader);
		}

		virtual OpenViBE::boolean isBufferReceived()
		{
			return m_pCodec->isOutputTriggerActive(OVP_GD_Algorithm_SignalStreamDecoder_OutputTriggerId_ReceivedBuffer);
		}

		virtual OpenViBE::boolean isEndReceived()
		{
			return m_pCodec->isOutputTriggerActive(OVP_GD_Algorithm_SignalStreamDecoder_OutputTriggerId_ReceivedEnd);
		}
	};
};

#endif // TARGET_HAS_ThirdPartyOpenViBEPluginsGlobalDefines

#endif //__OpenViBEToolkit_TSignalDecoder_H__
