#include "DateTime.h"

namespace System{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	long dateData;

	DateTime::DateTime()
	{
	}

	DateTime::DateTime(long long ticks)
	{
		if (ticks < 0L || ticks > 3155378975999999999L)
		{
			//throw new ArgumentOutOfRangeException("ticks", "ArgumentOutOfRange_DateTimeBadTicks");
		}
		this->DateData = ticks;
		this->TicksPerMillisecond = time_duration::ticks_per_second()/1000;
	}

	DateTime::DateTime(int year, int month, int day)
	{
		ptime time_t_epoch(date(1970,1,1));
		ptime d(date(year,month,day));
		time_duration diff = d - time_t_epoch;
		//DateTime(diff.ticks());
		this->DateData=diff.ticks();
		this->TicksPerMillisecond = time_duration::ticks_per_second()/1000;
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
		/*static std::locale loc(std::wcout.getloc(), new wtime_facet(L"%d/%m/%Y %H:%M:%S"));*/

		ptime epoch(date(1970,1,1));
		time_duration duration = milliseconds(this->DateData/this->TicksPerMillisecond);
		ptime t = epoch + duration;

		std::string s;
		std::ostringstream datetime_ss;
		::boost::posix_time::time_facet * p_time_output = new ::boost::posix_time::time_facet;
		std::locale special_locale (std::locale(""), p_time_output);
		// special_locale takes ownership of the p_time_output facet
		datetime_ss.imbue (special_locale);
		(*p_time_output).format("%x %X"); // date time
		datetime_ss << t;
		s = datetime_ss.str().c_str();
		return new String(s.data());
	}
}