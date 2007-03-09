#ifndef __OpenViBEToolkit_Writer_IBoxAlgorithmSignalOutputWriter_H__
#define __OpenViBEToolkit_Writer_IBoxAlgorithmSignalOutputWriter_H__

#include "ovtkIBoxAlgorithmOutputWriter.h"

namespace OpenViBEToolkit
{
	class OVTK_API IBoxAlgorithmSignalOutputWriter : virtual public OpenViBEToolkit::IBoxAlgorithmOutputWriter
	{
	public:

		virtual OpenViBE::boolean setSamplingRate(const OpenViBE::uint32 ui32SamplingRate)=0;
		virtual OpenViBE::boolean setChannelCount(const OpenViBE::uint32 ui32ChannelCount)=0;
		virtual OpenViBE::boolean setChannelName(const OpenViBE::uint32 ui32ChannelIndex, const char* sChannelName)=0;
		virtual OpenViBE::boolean setSampleCount(const OpenViBE::uint32 ui32SampleCount)=0;
		virtual OpenViBE::boolean setSampleBuffer(const OpenViBE::float64* pSampleBuffer)=0;

		virtual OpenViBE::boolean writeHeader(EBML::IWriter& rWriter)=0;
		virtual OpenViBE::boolean writeBuffer(EBML::IWriter& rWriter)=0;

		_IsDerivedFromClass_(OpenViBEToolkit::IBoxAlgorithmOutputWriter, OVTK_ClassId_);
	};

	extern OVTK_API OpenViBEToolkit::IBoxAlgorithmSignalOutputWriter* createBoxAlgorithmSignalOutputWriter(void);
	extern OVTK_API void releaseBoxAlgorithmSignalOutputWriter(OpenViBEToolkit::IBoxAlgorithmSignalOutputWriter* pOutputWriter);
};

#endif // __OpenViBEToolkit_Writer_IBoxAlgorithmSignalOutputWriter_H__
