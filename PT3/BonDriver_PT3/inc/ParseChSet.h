#pragma once

#include "Util.h"
#include "StringUtil.h"

typedef std::basic_string<_TCHAR> tstring;

#if defined(UNICODE) || defined(_UNICODE)
# define tifstream std::wifstream
//#define locale_japan() {std::locale::global(locale("jananese"));}
#else
# define tifstream std::ifstream
//#define locale_japan() {std::locale::global(locale("ja_JP.UTF-8"));}
#endif

typedef struct _CH_DATA{
	DWORD dwPT1Ch;		// ini�Œ�`���ꂽPT3�`�����l��
	ULONG ulTSID;		// ini�Œ�`���ꂽTSID
	tstring tszName;	// ini�Œ�`���ꂽ�`�����l����
	//=�I�y���[�^�[�̏���
	_CH_DATA(void){
		dwPT1Ch = 0;
		ulTSID = 0;
		tszName = _T("");
	};
	~_CH_DATA(void){
	}
	_CH_DATA & operator= (const _CH_DATA & o) {
		dwPT1Ch = o.dwPT1Ch;
		ulTSID = o.ulTSID;
		tszName = o.tszName;
		return *this;
	}
}CH_DATA;

typedef struct _SPACE_DATA {
	tstring tsKeyword;	// ini�Œ�`���ꂽSpaceXXX ��Space���������������Z�b�g
	CHAR cSpace;		// ini�Œ�`���ꂽ�`�����l���X�y�[�X 0�`X �g�p���Ȃ�����-1
	UCHAR ucChannelCnt;	// ini�Œ�`���ꂽ�`�����l����
	tstring tszName;	// ini�Œ�`���ꂽ�`���[�j���O�X�y�[�X����
	vector<CH_DATA>chVec;
	_SPACE_DATA(void) {
		tsKeyword = _T("");
		cSpace = -1;
		ucChannelCnt = 0;
		tszName = _T("");
	};
	~_SPACE_DATA(void) {
	}
	_SPACE_DATA& operator= (const _SPACE_DATA& o) {
		tsKeyword = o.tsKeyword;
		cSpace = o.cSpace;
		ucChannelCnt = o.ucChannelCnt;
		tszName = o.tszName;
		chVec = o.chVec;
		return *this;
	}
}SPACE_DATA;



class CParseChSet
{
public:
	vector<SPACE_DATA> spaceVec;

public:
	CParseChSet(void);
	~CParseChSet(void);

	//ChSet.txt�̓ǂݍ��݂��s��
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// file_path		[IN]ChSet.txt�̃t���p�X
	BOOL ParseText(
		LPCTSTR filePath
		);

protected:
	BOOL Parse1Line(tstring parseLine, SPACE_DATA& info );
	BOOL Parse1Line(tstring parseLine, CH_DATA& chInfo );
};
