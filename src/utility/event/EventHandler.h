#ifndef SMARTSENSORS_EVENTHANDLER_H
#define SMARTSENSORS_EVENTHANDLER_H

#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include <QThread>

/*
 * @brief EventHandler
 * This class is used to manage events
 * @tparam Args the arguments of the event
 * @note this class is thread safe
 * @note this class is used to manage events with arguments
 */
template<typename... Args>
class EventHandler {
public:
	using Callback = std::function<void(Args...)>;
	/*
	 * @brief subscribe
	 * This method is used to subscribe to an event
	 * @param callback the callback to call when the event is triggered
	 */
	void subscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target_type() == callback.target_type();
		});
		if (it == callbacks.end())
		callbacks.push_back(callback);
	}
	/*
	 * @brief unsubscribe
	 * This method is used to unsubscribe from an event
	 * @param callback the callback to unsubscribe
	 */
	void unsubscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target_type() == callback.target_type();
		});
		if (it != callbacks.end()) {
			callbacks.erase(it);
		}
	}
	/*
	 * @brief notify
	 * This method is used to notify the event
	 * @param args the arguments of the event
	 */
	void notify(Args... args) {
		for (const auto& callback : callbacks) {
			callback(args...);
		}
	}
	/*
	 * @brief notifyAsync
	 * This method is used to notify the event asynchronously
	 * @param args the arguments of the event
	 */
	void notifyAsync(Args... args) {
		std::thread([this, args...]() {
		  notify(args...);
		}).detach();
	}


private:
	std::vector<Callback> callbacks;
};
/*
 * @brief EventHandlerVoid
 * This class is used to manage events
 * @note this class is thread safe
 * @note this class is used to manage events without arguments
 */
class EventHandlerVoid {
public:
	using Callback = std::function<void()>;
	/*
	 * @brief subscribe
	 * This method is used to subscribe to an event
	 * @param callback the callback to call when the event is triggered
	 */
	void subscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target_type() == callback.target_type();
		});
		if (it == callbacks.end())
		callbacks.push_back(callback);
	}
	/*
	 * @brief unsubscribe
	 * This method is used to unsubscribe from an event
	 * @param callback the callback to unsubscribe
	 */
	void unsubscribe(Callback callback) {
		auto it = std::find_if(callbacks.begin(), callbacks.end(), [&callback](const Callback& cb) {
		  return cb.target_type() == callback.target_type();
		});

		if (it != callbacks.end()) {
			callbacks.erase(it);
		}
	}
	/*
	 * @brief notify
	 * This method is used to notify the event
	 */
	void notify() {
		for (const auto& callback : callbacks) {
			callback();
		}
	}
	/*
	 * @brief notifyAsync
	 * This method is used to notify the event asynchronously
	 */
	void notifyAsync() {
		std::thread([this]() {
		  notify();
		}).detach();
	}

private:
	std::vector<Callback> callbacks;
};
#endif //SMARTSENSORS_EVENTHANDLER_H
