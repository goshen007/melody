#pragma once

#include "CFFT.h"
#include "scopeguard.h"
#include <functional>
#include <assert.h>
#include <vector>
#include <algorithm>

//������
struct Note {
	int frequnce;	//Ƶ��
	float time;		//ʱ��
	float velocity;	//����
	int lyric;		//���λ��
};

class CPitchShifting {
private:
	int m_windowSize;
	unsigned long m_sampleCount;
	int m_STFTRow;
	int m_STFTCol;
	int m_hop;
	int m_finalSampleCount;
	double m_scale;
	std::vector<std::function<void()>> m_deleter;
	complex** m_STFTOut;
	float** m_PVProcessOut;
	float* m_phaseVocoderOut;
private:
	void Init( int pitch, double scale );
	void doScalingAndShifting( short* dataIn, int pitch, double scale );
	void STFT(short* dataIn);
	void PVProcess();
	void ISTFT();
public:
	CPitchShifting();
	//���б��ٺͱ��
	short* TimeScalingAndPitchShifting(const Note& note, short* dataIn,unsigned long sampleCount);
	unsigned long GetFinalSampleCount() { return m_finalSampleCount; }


};