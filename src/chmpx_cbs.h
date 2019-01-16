/*
 * CHMPX
 *
 * Copyright 2015 Yahoo! JAPAN corporation.
 *
 * CHMPX is inprocess data exchange by MQ with consistent hashing.
 * CHMPX is made for the purpose of the construction of
 * original messaging system and the offer of the client
 * library.
 * CHMPX transfers messages between the client and the server/
 * slave. CHMPX based servers are dispersed by consistent
 * hashing and are automatically laid out. As a result, it
 * provides a high performance, a high scalability.
 *
 * For the full copyright and license information, please view
 * the license file that was distributed with this source code.
 *
 * AUTHOR:   Takeshi Nakatani
 * CREATE:   Mon Feb 27 2017
 * REVISION:
 *
 */

#ifndef CHMPX_CBS_H
#define CHMPX_CBS_H

#include "chmpx_common.h"

//---------------------------------------------------------
// Typedefs
//---------------------------------------------------------
typedef std::map<std::string, Nan::Callback*>	cbsmap;

//---------------------------------------------------------
// StackEmitCB Class
//---------------------------------------------------------
class StackEmitCB
{
	protected:
		cbsmap			EmitCbsMap;
		volatile int	lockval;				// lock variable for mapping

	protected:
		Nan::Callback* RawFind(const char* pemitname);

	public:
		StackEmitCB();
		virtual ~StackEmitCB();

		Nan::Callback* Find(const char* pemitname);
		bool Set(const char* pemitname, Nan::Callback* cbfunc);
		bool Unset(const char* pemitname);
};

#endif

/*
 * VIM modelines
 *
 * vim:set ts=4 fenc=utf-8:
 */
