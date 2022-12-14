#include "s_diagramnode.hpp"

XLELib::FF::S_DiagramNodeError::S_DiagramNodeError(std::string msg) {
	error = "[XLELib FF S_DiagramNodeError] " + msg;
}

const char* XLELib::FF::S_DiagramNodeError::what() const throw() {
	return error.c_str();
}

XLELib::FF::S_DiagramNode::S_DiagramNode() : Conversion() {
	init_conversion();
}

XLELib::FF::S_DiagramNode::S_DiagramNode(std::string input_file) : Conversion(input_file) {
	init_conversion();
}

XLELib::FF::S_DiagramNode::~S_DiagramNode() {
	
}

void XLELib::FF::S_DiagramNode::init_conversion() {
	class_pointer = this;
	conversions = {
		{L"V.3", 15, L"V.2", 14, &convert_3_15_to_2_14}
	};
}

void XLELib::FF::S_DiagramNode::convert_3_15_to_2_14() {
	/* Remove the column for claimable guild coins. */
	this->resize_at_end(L"V.2", 14);
}
