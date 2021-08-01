#pragma once

#include <memory>
#include <cassert>


template<typename>
class MyFunction;

template<typename ReturnType, typename ... Args>
class MyFunction<ReturnType(Args...)>
{
	class ICallable;
	template <typename T>
	class CallableT;

public:
	template <typename T>
	MyFunction& operator=(T t)
	{
		callable_ = std::make_unique<CallableT<T>>(t);
		return *this;
	}

	ReturnType operator()(Args... args) const
	{
		assert(callable_);
		return callable_->Invoke(args...);
	}

private:

	
	std::unique_ptr<ICallable> callable_;

};

template<typename ReturnType, typename ... Args>
class MyFunction<ReturnType(Args...)>::
	ICallable {
public:
	virtual ~ICallable() = default;
	virtual ReturnType Invoke(Args...) = 0;
};

template<typename ReturnType, typename ... Args>
template <typename T>
class MyFunction<ReturnType(Args...)>::
	CallableT : public ICallable {
public:
	CallableT(const T& t)
		: t_(t) {
	}

	~CallableT() override = default;

	ReturnType Invoke(Args... args) override {
		return t_(args...);
	}

private:
	T t_;
};


