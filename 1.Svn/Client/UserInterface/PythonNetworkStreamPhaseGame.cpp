//Find
	rkPlayer.SetStatus(PointChange.Type, PointChange.value);
	
///Change
#if defined(REFRESH_MONEY_SLEEP)
		if (PointChange.Type == POINT_GOLD) {
			auto DoChanges = [=](long val, bool IsGrowing) {
				for (; val <= PointChange.value && IsGrowing; val++) {
					CPythonPlayer::Instance().SetStatus(PointChange.Type, val);
					std::this_thread::sleep_for(std::chrono::microseconds(1));
				}
				for (; val >= PointChange.value && !IsGrowing; val--) {
					CPythonPlayer::Instance().SetStatus(PointChange.Type, val);
					std::this_thread::sleep_for(std::chrono::microseconds(1));
				}
			};
			std::thread mythread(DoChanges, CPythonPlayer::Instance().GetStatus(PointChange.Type), CPythonPlayer::Instance().GetStatus(PointChange.Type) < PointChange.value);
			mythread.detach(); // do not use join()
		}
		else
#endif
		rkPlayer.SetStatus(PointChange.Type, PointChange.value);