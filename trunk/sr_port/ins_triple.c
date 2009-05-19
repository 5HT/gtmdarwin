/****************************************************************
 *								*
 *	Copyright 2001, 2007 Fidelity Information Services, Inc	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

#include "mdef.h"

#include "compiler.h"
#include "mdq.h"

GBLREF triple *curtchain;

void ins_triple(triple *x)
{
	triple	*y;

	/* Need to pass a temporary variable "y" (instead of "curtchain->exorder.bl") to the dqins macro as it will
	 * otherwise result in incorrect queue insertion.
	 */
	y = curtchain->exorder.bl;
	dqins(y,exorder,x);
	CHKTCHAIN(curtchain);
}
