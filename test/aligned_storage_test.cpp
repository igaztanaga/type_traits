
//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "test.hpp"
#include "check_integral_constant.hpp"
#ifdef TEST_STD
#  include <type_traits>
#else
#  include <boost/type_traits/alignment_of.hpp>
#  include <boost/type_traits/aligned_storage.hpp>
#  include <boost/type_traits/is_pod.hpp>
#endif

template <class T>
void check(const T&)
{
   typedef typename tt::aligned_storage<T::value,T::value>::type t1;
   BOOST_MESSAGE(typeid(t1).name());
   BOOST_CHECK(::tt::alignment_of<t1>::value == T::value);
   BOOST_CHECK(sizeof(t1) == T::value);
#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
   BOOST_CHECK(::tt::is_pod<t1>::value == true);
#endif
   typedef typename tt::aligned_storage<T::value*2,T::value>::type t2;
   BOOST_MESSAGE(typeid(t2).name());
   BOOST_CHECK(::tt::alignment_of<t2>::value == T::value);
   BOOST_CHECK(sizeof(t2) == T::value*2);
#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
   BOOST_CHECK(::tt::is_pod<t2>::value == true);
#endif
}

TT_TEST_BEGIN(type_with_alignment)

check(tt::integral_constant<std::size_t,::tt::alignment_of<char>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<short>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<int>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<long>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<float>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<double>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<long double>::value>());

#ifdef BOOST_HAS_LONG_LONG
check(tt::integral_constant<std::size_t,::tt::alignment_of< ::boost::long_long_type>::value>());
#endif
#ifdef BOOST_HAS_MS_INT64
check(tt::integral_constant<std::size_t,::tt::alignment_of<__int64>::value>());
#endif
check(tt::integral_constant<std::size_t,::tt::alignment_of<int[4]>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<int(*)(int)>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<int*>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<VB>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<VD>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<enum_UDT>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<mf2>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<POD_UDT>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<empty_UDT>::value>());
check(tt::integral_constant<std::size_t,::tt::alignment_of<union_UDT>::value>());

TT_TEST_END








