#!/bin/sh
#
###########################################################################
#
#              Copyright (C) Autelan Technology
#
#This software file is owned and distributed by Autelan Technology 
#
############################################################################
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
#ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
#WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
#DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
#ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
#(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
#LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
#ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
#(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
#SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##############################################################################
#
# 
#
# CREATOR:
# autelan.software.team
# 
# DESCRIPTION: 
#ospf_auth_mode.sh AREA ON|OFF  MD5
#    
#############################################################################


source vtysh_start.sh
cmdstr="configure terminal
	router ospf"
if [ $# -eq 2 ] ; then
 	if [ $2 = "on" ] ; then		
        	cmdstr="$cmdstr
			area $1 authentication"	
	elif [ $2 = "off" ] ; then		
		cmdstr="$cmdstr
			no area $1 authentication"
	else		
		exit -3	
	fi	

elif [ $# -eq 3 ] ; then
	if [ $3 = "md5" ] ; then
 		if [ $2 = "on" ] ; then         
               		cmdstr="$cmdstr
                       		area $1 authentication message-digest"
        	elif [ $2 = "off" ] ; then
                 	cmdstr="$cmdstr
                        	no area $1 authentication "
        	else           
             		exit -3
        	fi 
	else
		exit -3
	fi     	
fi
echo $cmdstr
vtysh -c "$cmdstr"	
	if [ $? -eq 0 ] ; then		
		exit 0	
	else		
		exit -1	
	fi
