#ifndef COMPONENT_H
#define COMPONENT_H

#include <bitset>
#include "BitSize.h"

#include <unordered_map>
#include <typeinfo>
#include <string>
#include <iostream>
#include <assert.h>

namespace artemis {

		class Component {
			public:
				virtual ~Component() = 0;
			protected:
				Component() {};
		};

};

#endif
