#ifndef SMARTSENSORS_EVENTHANDLER_H
#define SMARTSENSORS_EVENTHANDLER_H

#include <iostream>
#include <functional>
#include <vector>

template<typename... Args>
class EventHandler {
public:
	using Callback = std::function<void(Args...)>;

	void subscribe(Callback callback) {
		callbacks.push_back(callback);
	}

	void unsubscribe(Callback callback) {
		auto it = std::find(callbacks.begin(), callbacks.end(), callback);
		if (it != callbacks.end()) {
			callbacks.erase(it);
		}
	}

	void notify(Args... args) {
		for (const auto& callback : callbacks) {
			callback(args...);
		}
	}

	void notifyAsync(Args... args) {
		for (const auto& callback : callbacks) {
			std::thread* t = new std::thread(callback, args...);
		}
	}

private:
	std::vector<Callback> callbacks;
};

class EventHandlerVoid {
public:
	using Callback = std::function<void()>;

	void subscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target<void()>() == callback.target<void()>();
		});

		if (it == callbacks.end()) {
			callbacks.push_back(callback);
		}
	}

	void unsubscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target<void()>() == callback.target<void()>();
		});

		if (it != callbacks.end()) {
			callbacks.erase(it);
		}
	}

	void notify() {
		for (const auto& callback : callbacks) {
			callback();
		}
	}

	void notifyAsync() {
		for (const auto& callback : callbacks) {
			std::thread* t = new std::thread(callback);
		}
	}

private:
	std::vector<Callback> callbacks;
};

#endif //SMARTSENSORS_EVENTHANDLER_H
