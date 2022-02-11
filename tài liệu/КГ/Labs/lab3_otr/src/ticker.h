// ---------------------------------------------------------------------------

#ifndef tfrequency_timerH
#define frequency_timerH
// ---------------------------------------------------------------------------

class FrequencyTimer {
public:
	FrequencyTimer();
	FrequencyTimer(double Unit);
	void Start(); // запускает таймер
	void Stop(); // ставит таймер на паузу
	void Reset(); // сбрасывает таймер
	double GetTime(); // возвращает время в заданных единицах измерения
	void SetMeasurementUnit(double Unit); // устанавливает единицы измерения:
	// 1000000 - микросекунды
	// 1000 - милисекунды
	// 1 - секунды,
	// 1/60 - минуты
	// 1/3600 - часы
	// 1/86400 - дни

private:
	__int64 StartingTime, EndingTime;
	__int64 Frequency;
	double ElapsedTime;
	double MeasurementUnit;
};

// ---------------------------------------------------------------------------
#endif
