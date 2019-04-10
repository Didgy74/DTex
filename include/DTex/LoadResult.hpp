#pragma once

#include <variant>
#include <cassert>

#include "Typedefs.hpp"

namespace DTex
{
	template<typename T>
	class LoadResult
	{
	public:
		LoadResult() = delete;
		LoadResult(const LoadResult&) = default;
		LoadResult(LoadResult&&) = default;
		constexpr explicit LoadResult(ResultInfo result);
		constexpr explicit LoadResult(T&& data);

		LoadResult& operator=(const LoadResult&) = default;
		LoadResult& operator=(LoadResult&&) = default;

		constexpr ResultInfo GetResultInfo() const;
		constexpr T& GetValue();
		constexpr const T& GetValue() const;
	private:
		ResultInfo resultInfo;
		std::variant<uint8_t, T> data;
	};

	template<typename T>
	inline constexpr LoadResult<T>::LoadResult(ResultInfo result) :
		resultInfo(result),
		data(uint8_t{})
	{
		assert(resultInfo != ResultInfo::Success);
	}

	template<typename T>
	inline constexpr LoadResult<T>::LoadResult(T&& data) :
		resultInfo(ResultInfo::Success),
		data(std::move(data))
	{
	}

	template<typename T>
	inline constexpr ResultInfo LoadResult<T>::GetResultInfo() const
	{
		return resultInfo;
	}

	template<typename T>
	inline constexpr T& LoadResult<T>::GetValue()
	{
		return std::get<T>(data);
	}

	template<typename T>
	inline constexpr const T& LoadResult<T>::GetValue() const
	{
		return std::get<T>(data);
	}
}