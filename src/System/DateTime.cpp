#include "DateTime.h"

namespace System{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	long dateData;

	DateTime::DateTime()
	{
		TicksPerMillisecond = time_duration::ticks_per_second()/1000;
	}

	DateTime::DateTime(long long ticks)
	{
		if (ticks < 0L || ticks > 3155378975999999999L)
		{
			//throw new ArgumentOutOfRangeException("ticks", "ArgumentOutOfRange_DateTimeBadTicks");
		}
		this->DateData = ticks;
		TicksPerMillisecond = time_duration::ticks_per_second()/1000;
	}

	DateTime::DateTime(int year, int month, int day)
	{
		ptime time_t_epoch(date(year,month,day));
		this->DateData = static_cast<unsigned long>(time_t_epoch.time_of_day().ticks());
		std::cout << this->DateData << std::endl;
	}

	DateTime* DateTime::GetNow()
	{
		ptime time_t_epoch(date(1970,1,1));
		ptime now = microsec_clock::local_time();
		time_duration diff = now - time_t_epoch;
		return new DateTime(diff.ticks());
	}

	DateTime* DateTime::GetUtcNow()
	{
		ptime time_t_epoch(date(1970,1,1));
		ptime now = microsec_clock::universal_time();
		time_duration diff = now - time_t_epoch;
		return new DateTime(diff.ticks());
	}

	String* DateTime::ToString()
	{
		static std::locale loc(std::wcout.getloc(), new wtime_facet(L"%d/%m/%Y %H:%M:%S"));
		std::basic_stringstream<> wss;
		wss.imbue(loc);
		
		ptime epoch(date(1970,1,1));
		time_duration duration = milliseconds(this->DateData/this->TicksPerMillisecond);
		ptime t = epoch + duration;

		wss << t;

		//const char* a = wss.str();
		std::wcout << wss.str() << std::endl;
		return new String("");
	}
}