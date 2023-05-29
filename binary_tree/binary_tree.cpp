#include <iostream>
#include <string>
#include <functional>
#include <tuple>
#include <vector>


#include "binary_tree.h"

void Binary_tree::print(Binary_tree* Node)
{
#define _MAX(x, y) ((x) > (y) ? (x) : (y))
#define _MIN(x, y) ((x) < (y) ? (x) : (y))

	auto RepStr = [](std::string const& s, size_t cnt) {
		if (ptrdiff_t(cnt) < 0)
			throw std::runtime_error("RepStr: Bad value " + std::to_string(ptrdiff_t(cnt)) + "!");
		std::string r;
		for (size_t i = 0; i < cnt; ++i)
			r += s;
		return r;
	};
	std::function<std::tuple<std::vector<std::string>, size_t, size_t>(Binary_tree const* Node, bool)> Rec;
	Rec = [&RepStr, &Rec](Binary_tree const* Node, bool left_child) {
		std::vector<std::string> lines;
		if (!Node)
			return std::make_tuple(lines, size_t(0), size_t(0));
		auto sval = (Node->value);
		auto resl = Rec(Node->left_child, true), resr = Rec(Node->right_child, false);
		auto const& vl = std::get<0>(resl);
		auto const& vr = std::get<0>(resr);
		auto cl = std::get<1>(resl), cr = std::get<1>(resr), lss = std::get<2>(resl), rss = std::get<2>(resr);
		size_t lv = sval.size();
		size_t ls = vl.size() > 0 ? lss : size_t(0);
		size_t rs = vr.size() > 0 ? rss : size_t(0);
		size_t lis = ls == 0 ? lv / 2 : _MAX(int(lv / 2 + 1 - (ls - cl)), 0);
		size_t ris = rs == 0 ? (lv + 1) / 2 : _MAX(int((lv + 1) / 2 - cr), (lis > 0 ? 0 : 1));
		size_t dashls = (ls == 0 ? 0 : ls - cl - 1 + lis - lv / 2), dashrs = (rs == 0 ? 0 : cr + ris - (lv + 1) / 2);
		//DEB(node->value); DEB(lv); DEB(ls); DEB(rs); DEB(cl); DEB(cr); DEB(lis); DEB(ris); DEB(dashls); DEB(dashrs); std::cout << std::endl;
		lines.push_back(
			(ls == 0 ? "" : (RepStr(" ", cl) + "/" + RepStr("-", dashls))) +
			sval + (rs == 0 ? "" : (RepStr("-", dashrs) + "\\" + RepStr(" ", rs - cr - 1)))
		);
		
		for (size_t i = 0; i < _MAX(vl.size(), vr.size()); ++i) {
			std::string sl = RepStr(" ", ls), sr = RepStr(" ", rs);
			if (i < vl.size()) sl = vl[i];
			if (i < vr.size()) sr = vr[i];
			sl = sl + RepStr(" ", lis);
			sr = RepStr(" ", ris) + sr;
			lines.push_back(sl + sr);
		}
		return std::make_tuple(lines, (left_child || ls + lis == 0 || lv % 2 == 1) ? ls + lis : ls + lis - 1, ls + lis + ris + rs);
	};
	auto v = std::get<0>(Rec(Node, true));
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << std::endl;

#undef _MAX
#undef _MIN
}

void Binary_tree::add_node(Binary_tree* Node, std::string new_value)
{
	if (Node->value > new_value)
	{
		if (Node->left_child != NULL)
		{
			add_node(Node->left_child, new_value);
		}
		else
		{
			Node->left_child = new Binary_tree();
			Node->left_child->value = new_value;
			Node->left_child->left_child = NULL;
			Node->left_child->right_child = NULL;
		}
	}

	else if(Node->value <= new_value)
	{
		if (Node->right_child != NULL)
		{
			add_node(Node->right_child, new_value);
		}
		else
		{
			Node->right_child = new Binary_tree();
			Node->right_child->value = new_value;
			Node->right_child->left_child = NULL;
			Node->right_child->right_child = NULL;
		}
	}
}

int Binary_tree::find_distance(Binary_tree* Node, std::string x, int level)
{
	if (Node == NULL)
	{
		return -1;
	}

	int distance = 0;

	if (Node->value == x)
	{
		return level;
	}

	else
	{
		int left = find_distance(Node->left_child, x, level + 1);
		int right = find_distance(Node->right_child, x, level + 1);
		return (left != -1) ? left : right;
	}
}

int Binary_tree::max_depth(Binary_tree* Node)
{
	if (Node == NULL)
	{
		return -1;
	}
	else
	{
		int left_depth = max_depth(Node->left_child);
		int right_depth = max_depth(Node->right_child);

		if (left_depth > right_depth)
		{
			return (left_depth + 1);
		}
		else
		{
			return (right_depth + 1);
		}
	}
}

void Binary_tree::direct_order(Binary_tree* Node)
{
	if (Node == NULL)
	{
		return;
	}

	std::cout << Node->value << " ";
	direct_order(Node->left_child);
	direct_order(Node->right_child);
}

void Binary_tree::symmetric_order(Binary_tree* Node)
{
	if (Node == NULL)
	{
		return;
	}

	symmetric_order(Node->left_child);
	std::cout << Node->value << " ";
	symmetric_order(Node->right_child);
}