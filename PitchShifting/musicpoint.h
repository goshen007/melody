#pragma once
#include <vector>
//������
struct Note {
	int frequnce;	//Ƶ��
	float time;		//ʱ��
	float velocity;	//����
};

//����㡣������о���ĸ�ʣ��Լ���Ҫ�����ߵȵ�
struct MusicPoint {
	Note note;		//����
	int lyricIndex;	//����±�
};





void CreateMusicPoints(std::vector<MusicPoint>& musicPoints);