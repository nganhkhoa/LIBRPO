#ifndef ROLE_H
#define ROLE_H

#include <string>

typedef struct _Role {
	int RoleId;
	std::string RoleName;
	std::string RoleDesc;
	unsigned int Price;
} Role;

#endif