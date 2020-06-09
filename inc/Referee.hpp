#pragma once

#include <iostream>
#include <string>
#include <map>

class Referee
{
public:
	Referee() = default;
	~Referee() = default;

	void	process_scores_in_file(std::string const& file_name);

	void	print_results(std::ostream& os = std::cout);
private:
	std::map<std::string, std::size_t> _m_scores_table;
};