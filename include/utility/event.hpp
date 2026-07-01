#pragma once
#include <functional>
#include <vector>


template<typename... Args>
class Event{
    
public:
    using Callback = std::function<void(Args...)>;

    void add(Callback callback) {
        listeners_.push_back(std::move(callback));
    }

    void broadcast(Args... args) const {
        for (const auto& listener : listeners_) {
            listener(args...);
        }
    }

private:
    std::vector<Callback> listeners_;
};