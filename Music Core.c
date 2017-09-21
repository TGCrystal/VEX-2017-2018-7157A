float bpm = 120.0;
int transposition = 0;

float mGetFrequency(int note, int octave)
{
	if(transposition != 0)
	{
		note += transposition;
		while(note > 12)
		{
			note -= 12;
			octave++;
		}
		while(note < 1)
		{
			note += 12;
			octave--;
		}
	}
	float base;
	float multiplier;
	switch(note) {
		case 1:
			base = 16.35;
			break;
		case 2:
			base = 17.32;
			break;
		case 3:
			base = 18.35;
			break;
		case 4:
			base = 19.45;
			break;
		case 5:
			base = 20.6;
			break;
		case 6:
			base = 21.83;
			break;
		case 7:
			base = 23.12;
			break;
		case 8:
			base = 24.5;
			break;
		case 9:
			base = 25.96;
			break;
		case 10:
			base = 27.5;
			break;
		case 11:
			base = 29.14;
			break;
		case 12:
			base = 30.87;
			break;
	}
	switch(octave) {
		case 0:
			multiplier = 1.0;
			break;
		case 1:
			multiplier = 2.0;
			break;
		case 2:
			multiplier = 4.0;
			break;
		case 3:
			multiplier = 8.0;
			break;
		case 4:
			multiplier = 16.0;
			break;
		case 5:
			multiplier = 32.0;
			break;
		case 6:
			multiplier = 64.0;
			break;
		case 7:
			multiplier = 128.0;
			break;
		case 8:
			multiplier = 256.0;
			break;
	}
	return (base*multiplier);
}

float mGetDuration(float division)
{
	float quarterTime = 6000/bpm;
	return quarterTime * (4/division);
}

void PlayNote(float frequency, float duration)
{
	playImmediateTone(frequency, duration);
	wait1Msec(duration*10);
}

void mR(float division)
{
	wait1Msec((mGetDuration(division))*10);
}
void mC(int octave, float division)
{
	PlayNote(mGetFrequency(1, octave), mGetDuration(division));
}
void mDF(int octave, float division)
{
	PlayNote(mGetFrequency(2, octave), mGetDuration(division));
}
void mD(int octave, float division)
{
	PlayNote(mGetFrequency(3, octave), mGetDuration(division));
}
void mEF(int octave, float division)
{
	PlayNote(mGetFrequency(4, octave), mGetDuration(division));
}
void mE(int octave, float division)
{
	PlayNote(mGetFrequency(5, octave), mGetDuration(division));
}
void mF(int octave, float division)
{
	PlayNote(mGetFrequency(6, octave), mGetDuration(division));
}
void mGF(int octave, float division)
{
	PlayNote(mGetFrequency(7, octave), mGetDuration(division));
}
void mG(int octave, float division)
{
	PlayNote(mGetFrequency(8, octave), mGetDuration(division));
}
void mAF(int octave, float division)
{
	PlayNote(mGetFrequency(9, octave), mGetDuration(division));
}
void mA(int octave, float division)
{
	PlayNote(mGetFrequency(10, octave), mGetDuration(division));
}
void mBF(int octave, float division)
{
	PlayNote(mGetFrequency(11, octave), mGetDuration(division));
}
void mB(int octave, float division)
{
	PlayNote(mGetFrequency(12, octave), mGetDuration(division));
}

void mCF(int octave, float division)
{
	mB((octave - 1), division);
}
void mFF(int octave, float division)
{
	mE(octave, division);
}

void mAS(int octave, float division)
{
	mBF(octave, division);
}
void mBS(int octave, float division)
{
	mC((octave+1), division);
}
void mCS(int octave, float division)
{
	mDF(octave, division);
}
void mDS(int octave, float division)
{
	mEF(octave, division);
}
void mES(int octave, float division)
{
	mF(octave, division);
}
void mFS(int octave, float division)
{
	mGF(octave, division);
}
void mGS(int octave, float division)
{
	mAF(octave, division);
}