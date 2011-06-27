C    Loglan82 Compiler&Interpreter
C     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
C     Copyright (C)  1993, 1994 LITA, Pau
C     
C     This program is free software; you can redistribute it and/or modify
C     it under the terms of the GNU General Public License as published by
C     the Free Software Foundation; either version 2 of the License, or
C     (at your option) any later version.
C     
C     This program is distributed in the hope that it will be useful,
C     but WITHOUT ANY WARRANTY; without even the implied warranty of
C     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
C     GNU General Public License for more details. File: LICENSE.GNU
C  ===============================================================     

	integer function ibset(i,j)
	integer i, j
	ibset= or(i,lshift(1,j))
	return
	end

	integer function ibclr(i,j)
	integer i,j
	ibclr = xor(i,and(i,lshift(1,j)))
	return
	end

	logical function btest(i,j)
	integer i,j
	btest = and(i,lshift(1,j)) .ne. 0
	return
	end

	integer function iand(i,j)
	integer i,j
	iand = and(i,j)
	return
	end

	integer function ior(i,j)
	integer i,j
	ior = or(i,j)
	return
	end

	integer function ieor(i,j)
	integer i,j
	ieor = xor(i,j)
	return
	end

	integer function ishft(i,j)
	integer i,j
        if (j .eq. 0) goto 11 
        if (j .gt. 0) goto 10
        i=and(i,X'7fffffff')
        ishft = rshift(i,-j)
        return
 10	ishft = lshift(i,j)
	return
 11     ishft = i
        return
	end

        character function int2char(i)
        integer i
        int2char=char(i)
        return
        end



