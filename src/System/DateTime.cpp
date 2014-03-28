#include "DateTime.h"

namespace System{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	long dateData;

	DateTime::DateTime()
	{
		_init();
	}

	DateTime::DateTime(long long ticks)
	{
		_init();
		if (ticks < 0L || ticks > 3155378975999999999L)
		{
			throw new ArgumentOutOfRangeException(new String("ticks"), new String("ArgumentOutOfRange_DateTimeBadTicks"));
		}

		this->DateData = ticks;		
	}

	DateTime::DateTime(int year, int month, int day)
	{
		_init();
		ptime d(date(year,month,day));
		time_duration diff = d - time_t_epoch;		
		this->DateData=diff.ticks();		
	}

	DateTime* DateTime::AddMilliseconds(int milliseconds)
	{		
		DateData += (int)(milliseconds/this->TicksPerMillisecond);
		return this;
	}

	void DateTime::_init()
	{
		this->time_t_epoch = ptime(date(1970,1,1));
		this->TicksPerMillisecond = time_duration::ticks_per_second()/1000;
	}

	DateTime* DateTime::getNow()
	{
		ptime now = microsec_clock::local_time();
		time_duration diff = now - time_t_epoch;
		return new DateTime(diff.ticks());
	}

	DateTime* DateTime::getUtcNow()
	{
		ptime now = microsec_clock::universal_time();
		time_duration diff = now - time_t_epoch;
		return new DateTime(diff.ticks());
	}

	String* DateTime::ToString()
	{
		/*static std::locale loc(std::wcout.getloc(), new wtime_facet(L"%d/%m/%Y %H:%M:%S"));*/
		time_duration duration = milliseconds(this->DateData/this->TicksPerMillisecond);
		ptime t = time_t_epoch + duration;

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