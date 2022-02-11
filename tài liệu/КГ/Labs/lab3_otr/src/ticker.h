// ---------------------------------------------------------------------------

#ifndef tfrequency_timerH
#define frequency_timerH
// ---------------------------------------------------------------------------

class FrequencyTimer {
public:
	FrequencyTimer();
	FrequencyTimer(double Unit);
	void Start(); // ��������� ������
	void Stop(); // ������ ������ �� �����
	void Reset(); // ���������� ������
	double GetTime(); // ���������� ����� � �������� �������� ���������
	void SetMeasurementUnit(double Unit); // ������������� ������� ���������:
	// 1000000 - ������������
	// 1000 - �����������
	// 1 - �������,
	// 1/60 - ������
	// 1/3600 - ����
	// 1/86400 - ���

private:
	__int64 StartingTime, EndingTime;
	__int64 Frequency;
	double ElapsedTime;
	double MeasurementUnit;
};

// ---------------------------------------------------------------------------
#endif
