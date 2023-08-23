#ifndef TICKET_HPP_INCLUDED
#define TICKET_HPP_INCLUDED

	void Ticket::insertEntryTime() {
		time(&t);
		struct tm *tempoInsert = localtime(&t);
		tempo = *tempoInsert;
	} 
#endif  