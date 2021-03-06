#pragma once
#include <boost/math/constants/constants.hpp>
#include <boost/assert.hpp>
#include "Defines.h"
#include "GeometryCast.h"


IN_NAEMSPACE_GEOMETRY(nm_Angles)
struct angle_t;
struct radian_t;

angle_t operator-(angle_t, angle_t);
angle_t operator+(angle_t, angle_t);
radian_t operator-(radian_t, radian_t);
angle_t operator+(angle_t, angle_t);

angle_t toAngle(radian_t rad);
radian_t toRadian(angle_t angle);





struct angle_t {
	using value_type = double;
	const value_type angle;
	explicit angle_t(value_type angle) :angle(angle) {
		BOOST_ASSERT_MSG(angle >= 0 && angle <= 180, "invalid angle");
	}

	operator value_type() const {
		BOOST_ASSERT_MSG(angle >= 0 && angle <= 180, "invalid angle");
		return angle;
	}
	//180 degree
	NODISCARD static angle_t max() {
		return angle_t(180);
	}
	//0 degree
	NODISCARD static angle_t min() {
		return angle_t(0);
	}

	//angle < 90
	NODISCARD bool isSharp() const;
	//angle > 90
	NODISCARD bool isObtuse() const;
	//sharp angle
	NODISCARD static angle_t SharpAngle(angle_t a);
	//obtuse angle
	NODISCARD static angle_t ObtuseAngle(angle_t a);
};


struct radian_t {
	using value_type = double;
	const value_type radian;
	static constexpr value_type pi = boost::math::constants::pi<value_type>();
	explicit radian_t(value_type radian) :radian(radian) {
		BOOST_ASSERT_MSG(radian >= 0 && radian <= pi, "invalid radian");
	}

	operator value_type() const {
		BOOST_ASSERT_MSG(radian >= 0 && radian <= pi, "invalid radian");
		return radian;
	}

	//pi radian
	NODISCARD static radian_t max() {
		return radian_t(pi);
	}
	//0 radian
	NODISCARD static radian_t min() {
		return radian_t(0);
	}

	//true-> radian < pi/2
	NODISCARD bool isSharp() const;
	//true-> radian >p/2
	NODISCARD bool isObtuse() const;
	//sharp angle with radian
	NODISCARD static radian_t SharpRadian(radian_t a);
	//obtuse angle with radian
	NODISCARD static radian_t ObtuseRadian(radian_t a);

};

END_NAMESPACE_GEOMETRY(nm_Angles)



BEGIN_GEOMETRY
template<>
inline nm_Angles::angle_t geometry_cast(nm_Angles::radian_t rad) {
	return nm_Angles::angle_t(rad.radian * 180 / nm_Angles::radian_t::pi);
}

template<>
inline nm_Angles::radian_t geometry_cast(nm_Angles::angle_t angle) {
	return nm_Angles::radian_t(angle.angle * nm_Angles::radian_t::pi / 180);
}
END_GEOMETRY