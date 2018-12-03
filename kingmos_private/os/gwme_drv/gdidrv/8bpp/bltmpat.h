/******************************************************
Copyright(c) ��Ȩ���У�1998-2003΢�߼�����������Ȩ����
******************************************************/


/*****************************************************
�ļ�˵����ͼ���豸��������(BLT & MERGE)
�汾�ţ�3.0.0
����ʱ�ڣ�2000-9-06
���ߣ�����
�޸ļ�¼��

******************************************************/

#ifndef FUNCTION
    #error not define FUNCTION!
#endif

#ifndef BLT_ROP
    #error not define BLT_ROP
#endif

static BOOL FUNCTION( _LPBLKBITBLT lpData )
{
    LPBYTE lpDestStart, lpDest;
	LPBYTE lpSrcStart, lpSrc;
    LPCBYTE lpPattern;
    WORD clrFore, clrBack;
    int i, j, n,  rows, cols, shift;
    BYTE mask, bitMask;
	int iSrcWidthBytes, iDestWidthBytes;
    
	iSrcWidthBytes = lpData->lpSrcImage->bmWidthBytes;
	iDestWidthBytes = lpData->lpDestImage->bmWidthBytes;

	lpDestStart = lpData->lpDestImage->bmBits + lpData->lprcDest->top * iDestWidthBytes + lpData->lprcDest->left;
	lpSrcStart = lpData->lpSrcImage->bmBits + lpData->lprcSrc->top * iSrcWidthBytes + lpData->lprcSrc->left;

    lpPattern = lpData->lpBrush->pattern;
    rows = lpData->lprcDest->bottom - lpData->lprcDest->top;
    cols = lpData->lprcDest->right - lpData->lprcDest->left;
    //shift = lpData->lprcMask->left & 0x07;
    clrFore = (WORD)lpData->lpBrush->color;
    clrBack = (WORD)lpData->solidBkColor;
    //n = lpData->lprcDest->top;

	if( lpData->lpptBrushOrg )
	{
		//shift = (lpData->lprcMask->left - lpData->lpptBrushOrg->x ) % 0x07;// + iWidthPat) % iWidthPat; 
		//n = lpData->lprcMask->top - lpData->lpptBrushOrg->y;
		shift = (lpData->lprcDest->left - lpData->lpptBrushOrg->x ) % 0x07;// + iWidthPat) % iWidthPat; 
		n = lpData->lprcDest->top - lpData->lpptBrushOrg->y;
	}
	else
	{
		shift = n = 0;
	}

    for( i = 0; i < rows; i++ )
    {
        mask = *(lpPattern+(n&0x07));
		n++; //LN 2003-05-06,����
        bitMask = 0x80 >> shift;
        lpDest = lpDestStart;
		lpSrc = lpSrcStart;
        for( j = 0; j < cols; j++ )
        {
            if( bitMask == 0 )
            {
                bitMask = 0x80;
            }
            if( mask & bitMask )
            {
                *lpDest = BLT_ROP( *lpSrc, (BYTE)clrFore );
            }
            else
                *lpDest = BLT_ROP( *lpSrc, (BYTE)clrBack );
            lpDest++;
			lpSrc++;
            bitMask >>= 1;
        }
        lpDestStart += iDestWidthBytes;
		lpSrcStart += iSrcWidthBytes;
    }
    return TRUE;
}
