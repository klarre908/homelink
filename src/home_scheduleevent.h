#ifndef __HOME_SCHEDULEEVENT_H__
#define __HOME_SCHEDULEEVENT_H__

namespace Home
{
	class ScheduleEvent
	{
	public:
		virtual void execute() = 0;

	protected:
		ScheduleEvent();

	private:
		int mId;
	};
}

#endif
