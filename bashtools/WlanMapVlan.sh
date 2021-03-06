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
# eag_init
#
# CREATOR:
# autelan.software.xxx. team
# 
# DESCRIPTION: 
#     
#############################################################################

MAND_PATH=/opt/awk/WlanMapVlan.awk
FILE_PATH=/var/run/apache2/WlanMapVlan.tmp
if [ $# -ne 1 ];then
	exit 1
fi
if [ ! -f $FILE_PATH ]
        then
                touch $FILE_PATH
                chmod 666 $FILE_PATH
fi
ip addr|awk -f $MAND_PATH | awk -v patt="$1" 'BEGIN{ FS=".";RS="\n" }{if($2==patt) print $0 }'>$FILE_PATH

