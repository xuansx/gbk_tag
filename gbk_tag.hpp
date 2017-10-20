#ifndef GBK_TAG_H_
#define GBK_TAG_H_

namespace Hanzi
{
	enum {
		HZ_Most_Common = 3755,
		HZ_Second_Common = 3008,
	};
	constexpr unsigned int  MakeU32(unsigned short higher, unsigned short lower)
	{
		unsigned int u32 = higher<<16;
		u32 |= lower;
		return u32;
	}
	enum eCharTypeHigh
	{
		CTH_Hanzi		= 0x80,
		CTH_Punctuation = 0x81,
		CTH_Number		= 0x82,
		CTH_Tab			= 0x84,
		CTH_Alpha		= 0x88,
	};
	enum eCharType :unsigned short
	{
		CT_NONE					= 0,
		CT_ASCII				= 0x0080,
		CT_NUM					= 0x0200,//0x30-0x39
		CT_CTRL					= 0x0400,
		CT_EN					= 0x08E0,//ascii:0x61-0x7A 0x41-0x5A
		CT_EN_UPER				= 0x08E1,//0x41-0x5A
		CT_EN_LOWER				= 0x08E2,//0x61-0x7A
		CT_PUNCTUATION			= 0x0100,//符号
		/*
		首字节在 81-FE 之间，尾字节在 40-FE 之间，剔除 xx7F 一条线
		a. GB 2312 汉字区。即 GBK/2: B0A1-F7FE。收录 GB 2312 汉字 6763 个，按原顺序排列。
		b. GB 13000.1 扩充汉字区。包含：
		(1) GBK/3: 8140-A0FE。收录 GB 13000.1 中的 CJK 汉字 6080 个。
		(2) GBK/4: AA40-FEA0。收录 CJK 汉字和增补的汉字 8160 个
		*/
		CT_GB					= 0x8000,//0x8140-0xA0FE AA40-FEA0
		CT_HANZI_CJK			= 0x8001,//big5   8140-A0FE
		CT_HANZI_GB				= 0x8002,//gb2312 B0A1-F7FE 常用字高位0xa1－0xfe，低位是 0xa1-0xfe
		CT_HANZI_LING			= 0x8003,//汉字数字〇：A996

		CT_GB_PUNCT				= 0x8100,//gb2312 标点与符号
		CT_GB_PUNCT_UNTAG		= 0x8180,//未标记符号
		CT_GB_PUNCT_VERTICAL	= 0x8101,//变形显现形式垂直符号：A6E0-A6F5（Punctuation）
		CT_GB_NUM				= 0x8200,
		CT_GB_NUM_ROMA_LOWER	= 0x8202,//小写罗马数字A2A1-A2AA（1-10）
		CT_GB_NUM_DOT			= 0x8203,//数字带点 A2B1-A2C4 （1-20）
		CT_GB_NUM_RBRACE		= 0x8204,//括号带数字 ~-A2D8（1-20）
		CT_GB_NUM_ROUND			= 0x8205,//带圆圈数字 ~-A2E2（1-10）
		CT_GB_NUM_HZ_RBRACE		= 0x8206,//汉字数字带括号A2E5~-A2EE（1-10）：（一）（二）。。。。
		CT_GB_NUM_ROMA_UPER		= 0x8207,//罗马数字A2F1~A2FC（1-12）

		CT_GB_PUNCT_TAB			= 0x8400,//制表符 制表符1：A871-A890 制表符2：A9A4-A9EF

		CT_GB_ALPHA				= 0x8800,
		CT_GB_JAPAN_ALPHA		= 0x8801,//平假名，片假名：A4A1-A5F6
		CT_GB_GREEK_ALPHA_UPER  = 0x8802,//希腊大写字母：A6A1-A6B8
		CT_GB_GREEK_ALPHA_LOWER = 0x8803,//希腊小写字母：A6C1-A6D8
		CT_GB_RUSSIAN_ALPHA_UPER= 0x8805,//西里尔文大写字母：A7A1-A7C1
		CT_GB_RUSSIAN_ALPHA_LOWER=0x8806,//西里尔文小写字母：A7D1-A7F1
		CT_GB_HZ_ZHUYIN			= 0x8808,//汉语注音：A8C5-A8E9
		CT_GB_HZ_PINYIN			= 0x88E2,//汉语拼音带声调字母，最后为手写g：A8A1-A8B8（aoeiuv四声）A8C0（^eamnng）
		
	};

	enum ePairPunctParam
	{
		Pair_Left = 0x4,
		Pair_Right = 0x8,
		Pair_Single = 0x1,
		Pair_Double = 0x2,
	};
	enum ePunctuationType:unsigned short
	{
		PT_None				= 0,
		PT_Tech				= 0x0100,
		PT_AT,
		PT_NUM,
		PT_Dollar,
		PT_RMB,
		PT_EU,
		PT_Percentage,
		PT_Permillage,
		PT_Tilde,//~意思是 颚化符号,鼻音化符号,代字号），中文 俗称 波浪号
		PT_AntiQuotation,//`
		PT_AND,//&
		PT_OR,//|
		PT_STAR,
		PT_PLUS,
		PT_MINUS,
		PT_LT,//<
		PT_GT,//>
		PT_EQ,//=
		PT_Slash,// /
		PT_Backlash,//"\\" 
		PT_Degree,
		PT_Minus,
		PT_Second,
		PT_DegreeC,//℃ 
		PT_DegreeF,//℉
		PT_Blank			= 0x1000,//空格
		PT_Period			= 0x1010,//句号(Dot)。
		PT_Question			= 0x1020,//问号？
		PT_Exclamation		= 0x1030,//叹号！
		PT_Comma			= 0x1040,//逗号，
		PT_Pause			= 0x1050,//顿号、
		PT_Semicolon		= 0x1060,//分号；
		PT_Colon			= 0x1070,//冒号：
		PT_Dash				= 0x1080,//破折号——
		PT_Ellipsis			= 0x1090,//省略号……
		PT_Hyphen			= 0x10A0,//连接号-
		PT_SeparationDot	= 0x10B0,//间隔号·
		PT_Pair				= 0x2000,//配对的符号 0bit Left,1bit Right,2bit single,3bit double
		PT_Parentheses		= 0x2010,//括号()（）
		PT_Brace			= 0x2020,//花括号{}｛｝
		PT_Quotation		= 0x2100,//引号"'“”‘’「」『』
		PT_SquareBrackets	= 0x2200,//方括号[]［］【】〖〗〔〕
		PT_SolidBrackets	= 0x2210,//【】实心方括号
		PT_HollowBrackets	= 0x2220,//〖〗空心方括号
		PT_ShellBrackets	= 0x2240,//〔〕龟壳形括号
		PT_AngleQuotes		= 0x2400,//书名号<>《》〈〉
		PT_Tab				= 0x4000,
		PT_Other			= 0x8000,
	};

	struct PairPunctuationInfo
	{
		ePunctuationType punctuationType;
		unsigned short type;
		bool isPair;
		bool isSingle;
		bool isLeft;
		PairPunctuationInfo(unsigned short ty)
			:type(ty),isPair(false),isSingle(false),isLeft(false)
		{
			if ((type & PT_Pair) == 0)
			{
				return;
			}

			punctuationType = (ePunctuationType)(ty & 0xFFF0);

			isPair = true;
			if (ty & 0x1)
			{
				isSingle = true;
			}
			if (ty & 0x2)
			{
				isSingle = false;
			}
			if (ty & 0x4)
			{
				isLeft = true;
			}
			if (ty & 0x8)
			{
				isLeft = false;
			}
		}
		PairPunctuationInfo(ePunctuationType ty, bool left, bool single)
			:type(ty), isPair(false), isSingle(false), isLeft(false)
		{
			type = ty;
			if ((type & PT_Pair) == 0)
			{
				return ;
			}
			if (left)
			{
				type |= 0x1;
			}
			else
			{
				type |= 0x2;
			}
			if (single)
			{
				type |= 0x4;
			}
			else
			{
				type |= 0x8;
			}
		}
		bool Available()const
		{
			return isPair;
		}
		unsigned short GetTypeDetail()const
		{
			return type;
		}
	};
	union Tag {
		Tag() :tag(0) {}
		Tag(unsigned int t):tag(t)
		{}
		struct 
		{
			union {
				struct {
					char		ch[2];
				};
				wchar_t			 wc;
				ePunctuationType punct;
			};
			eCharType type;
		};
		unsigned int  tag;
	};
	unsigned short GB2312_GetIndex(wchar_t ch)
	{
		if (ch >= 0xB0A1 && ch <= 0xF7FE)
		{
			unsigned char lower = ch & 0xFF;
			unsigned char higher = (ch >> 8) & 0xFF;

			register wchar_t c = ch - 0xA0A0;
			higher = c / 100;
			lower = c - higher * 100;
			if (higher >= (16) && higher <= (87) &&
				lower > 0 && lower <= 94)
			{
				unsigned short word = (lower - 1)*(higher-16);
				return word;
			}		
		}
		return 0;
	}
	unsigned int   ASCII_GetType(wchar_t ch)
	{
		if (ch > 32 && ch < 127)
		{
			if (ch <= 0x39 && ch >= 0x30)
			{
				return MakeU32(CT_NUM, ch - 0x30);
			}
			if (ch >= 0x41 && ch <= 0x5A)
			{
				return MakeU32(CT_EN_UPER, ch);
			}
			if (ch >= 0x61 && ch <= 0x7A)
			{
				return MakeU32(CT_EN_LOWER, ch);
			}
			switch (ch)
			{
			case '!':
				return MakeU32(CT_GB_PUNCT, PT_Exclamation);
			case '"':
				return MakeU32(CT_GB_PUNCT, PT_Quotation|0x2);
			case '#':
				return MakeU32(CT_GB_PUNCT, PT_NUM);
			case '$':
				return MakeU32(CT_GB_PUNCT, PT_Dollar);
			case '%':
				return MakeU32(CT_GB_PUNCT, PT_Percentage);
			case '&':
				return MakeU32(CT_GB_PUNCT, PT_AND);
			case '\''://39
				return MakeU32(CT_GB_PUNCT, PT_Quotation);
			case '(':
				return MakeU32(CT_GB_PUNCT, PT_Parentheses|Pair_Left);
			case ')':
				return MakeU32(CT_GB_PUNCT, PT_Parentheses | Pair_Right);
			case '*':
				return MakeU32(CT_GB_PUNCT, PT_STAR);
			case '+':
				return MakeU32(CT_GB_PUNCT, PT_PLUS);
			case ',':
				return MakeU32(CT_GB_PUNCT, PT_Comma);
			case '-':
				return MakeU32(CT_GB_PUNCT, PT_MINUS);
			case '.':
				return MakeU32(CT_GB_PUNCT, PT_Period);
			case '/':
				return MakeU32(CT_GB_PUNCT, PT_Slash);
			case ':':
				return MakeU32(CT_GB_PUNCT, PT_Colon);
			case ';':
				return MakeU32(CT_GB_PUNCT, PT_Semicolon);
			case '<':
				return MakeU32(CT_GB_PUNCT, PT_LT);
			case '?':
				return MakeU32(CT_GB_PUNCT, PT_Question);
			case '`':
				return MakeU32(CT_GB_PUNCT, PT_AntiQuotation);
			case '{':
				return MakeU32(CT_GB_PUNCT, PT_Brace|Pair_Left);
			case '|':
				return MakeU32(CT_GB_PUNCT, PT_OR);
			case '}':
				return MakeU32(CT_GB_PUNCT, PT_Brace | Pair_Right);
			case '~':
				return MakeU32(CT_GB_PUNCT, PT_Tilde);
			}
		}
		return CT_NONE;
	}

#define SKIP_CODE_SECTION_LESS(x) \
	if (ch < x)\
	{\
		return 0;\
	}\

	unsigned int GetPunctuationNum(wchar_t ch)
	{
		if (ch >= 0xA2A1 && ch <= 0xA2FC)
		{
			if (ch <= 0xA2AA)
			{
				return MakeU32(CT_GB_NUM_ROMA_LOWER, ch - 0xA2A1);
			}
			if (ch < 0xA2B1)
			{
				return 0;
			}
			if (ch <= 0xA2C4)
			{
				return MakeU32(CT_GB_NUM_DOT, ch - 0xA2B1);
			}
			if (ch <= 0xA2D8)
			{
				return MakeU32(CT_GB_NUM_RBRACE, ch - 0xA2C4 + 1);
			}
			if (ch <= 0xA2E2)
			{
				return MakeU32(CT_GB_NUM_ROUND, ch - 0xA2D8 + 1);
			}
			if (ch < 0xA2E5)
			{
				return 0;
			}
			if (ch <= 0xA2EE)
			{
				return MakeU32(CT_GB_NUM_HZ_RBRACE, ch - 0xA2E5);
			}
			if (ch < 0xA2F1)
			{
				return 0;
			}
			if (ch <= 0xA2FC)
			{
				return MakeU32(CT_GB_NUM_ROMA_UPER, ch - 0xA2F1);
			}
		}
		return 0;
	}
	unsigned int GetCharType(wchar_t ch)
	{
		if (ch < 0x8000)
		{
			if (ch >= 0x08 && ch <= 0x0D)
			{
				return MakeU32(CT_CTRL, ch);
			}
			{
				return ASCII_GetType(ch);
			}
		}
		else if (ch >= 0x8140 && ch <= 0xA0FE)
		{
			return MakeU32(CT_HANZI_CJK, ch);
		}
		else if (ch >= 0xA1A1 && ch <= 0xA9EF)//punctuation
		{
			//gb2312 标点与符号
			if (ch < 0xA1FE)
			{
				switch (ch)
				{
				case 0xA1A2:
				return MakeU32(CT_GB_PUNCT, PT_Pause);//、
				case 0xA1A3:
				return MakeU32(CT_GB_PUNCT, PT_Period);//.
				case 0xA1A4:
					return MakeU32(CT_GB_PUNCT, PT_SeparationDot);//·
				case 0xA1AA:
					return MakeU32(CT_GB_PUNCT, PT_Dash);//-
				case 0xA1AB:
					return MakeU32(CT_GB_PUNCT, PT_Tilde);//~
				case 0xA1AC://||
					return MakeU32(CT_GB_PUNCT_UNTAG, ch);
				case 0xA1AD://…
					return MakeU32(CT_GB_PUNCT, PT_Ellipsis);
				case 0xA1AE://‘
				{//(ePunctuationType ty, bool left, bool single)
					PairPunctuationInfo pair(PT_Quotation, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1AF://’
				{
					PairPunctuationInfo pair(PT_Quotation, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B0://“
				{
					PairPunctuationInfo pair(PT_Quotation, true, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B1://”
				{
					PairPunctuationInfo pair(PT_Quotation, false, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				//〔 〕 〈 〉 《 》 「 」 『 』 〖 〗 【 】
				case 0xA1B2://
				{
					PairPunctuationInfo pair(PT_ShellBrackets, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B3://
				{
					PairPunctuationInfo pair(PT_ShellBrackets, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B4://〈 〉
				{
					PairPunctuationInfo pair(PT_AngleQuotes, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}case 0xA1B5://
				{
					PairPunctuationInfo pair(PT_AngleQuotes, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B6://《 》
				{
					PairPunctuationInfo pair(PT_AngleQuotes, true, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B7://
				{
					PairPunctuationInfo pair(PT_AngleQuotes, false, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B8://「 」 
				{
					PairPunctuationInfo pair(PT_Quotation, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1B9://
				{
					PairPunctuationInfo pair(PT_Quotation, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BA://『 』
				{
					PairPunctuationInfo pair(PT_Quotation, true, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BB://
				{
					PairPunctuationInfo pair(PT_Quotation, false, false);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BC://【】
				{
					PairPunctuationInfo pair(PT_HollowBrackets, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BD://
				{
					PairPunctuationInfo pair(PT_HollowBrackets, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BE://〖〗
				{
					PairPunctuationInfo pair(PT_SolidBrackets, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				case 0xA1BF://
				{
					PairPunctuationInfo pair(PT_SolidBrackets, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
				}
				default:
					return MakeU32(CT_GB_PUNCT_UNTAG, ch);
					break;
				}
			}
			SKIP_CODE_SECTION_LESS(0xA2A1);
			//各类数字标示符号。
			if (ch < 0xA2FC)
			{
				return GetPunctuationNum(ch);
			}
			//此段完全映射到ASCII的打印字符段
			if (ch <= 0xA3FE)
			{
				return ASCII_GetType(ch-0xA3A1+33)|0x80000000;
			}
			SKIP_CODE_SECTION_LESS(0xA4A1);
			//平假名，片假名：A4A1-A5F6
			if (ch <= 0xA5F6)
			{
				return MakeU32(CT_GB_JAPAN_ALPHA, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA6A1);
			//CT_GB_GREEK_ALPHA_UPER = 0x810F,//希腊大写字母：A6A1-A6B8
			if (ch <= 0xA6B8)
			{
				return MakeU32(CT_GB_GREEK_ALPHA_UPER, ch - 0xA6A1);
			}				
			SKIP_CODE_SECTION_LESS(0xA6C1);
			//CT_GB_GREEK_ALPHA_LOWER = 0x8110,//希腊小写字母：A6C1-A6D8
			if (ch <= 0xA6D8)
			{
				return MakeU32(CT_GB_GREEK_ALPHA_LOWER, ch - 0xA6C1);
			}
			SKIP_CODE_SECTION_LESS(0xA6E0);
			//CT_GB_PUNCT_VERTICAL = 0x8111,//变形显现形式垂直符号：A6E0-A6F5（Punctuation）
			if (ch <= 0xA6F5)
			{				
				return MakeU32(CT_GB_PUNCT_VERTICAL, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA7A1);
			//CT_GB_RUSSIAN_ALPHA_UPER= 0x8112,//西里尔文大写字母：A7A1-A7C1
			if (ch <= 0xA7C1)
			{
				return MakeU32(CT_GB_RUSSIAN_ALPHA_UPER, ch - 0xA7A1);
			}
			SKIP_CODE_SECTION_LESS(0xA7D1);
			//CT_GB_RUSSIAN_ALPHA_LOWER= 0x8113,//西里尔文小写字母：A7D1-A7F1
			if (ch <= 0xA7F1)
			{
				return MakeU32(CT_GB_RUSSIAN_ALPHA_LOWER, ch - 0xA7D1);
			}
			SKIP_CODE_SECTION_LESS(0xA840);
			//CT_GB_PUNCT_1			= 0x8114,//标点与符号2：A840-A853
			if (ch <= 0xA853)
			{
				if (ch == 0xA848)
				{
					return MakeU32(CT_GB_PUNCT, PT_DegreeF);
				}
				else
				{
					return MakeU32(CT_GB_PUNCT_UNTAG, ch);
				}
				//return MakeU32(CT_GB_PUNCT_1, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA871);
			//CT_GB_PUNCT_TAB_0		= 0x8115,//制表符1：A871-A890
			if (ch <= 0xA890)
			{
				return MakeU32(CT_GB_PUNCT_TAB, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA891);
			//CT_GB_PUNCT_2			= 0x8116,标点和符号3：A891-A895（A848华氏度）（A894，A895“”）
			if (ch <= 0xA895)
			{
				return MakeU32(CT_GB_PUNCT_TAB, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA8A1);
			//CT_GB_HZ_PINYIN			= 0x8117,//汉语拼音：A8A1-A8B8（aoeiuv四声）A8C0（^eamnng）
			if (ch <= 0xA8C0)
			{
				static const char HZ_PINYIN[] = "aoeiuvmng";//v 为 ü
				if (ch <= 0xA8B8)
				{
					wchar_t py = HZ_PINYIN[((ch - 0xA8A1)/4)&0xFF];
					wchar_t py_shengdiao = ((ch - 0xA8A1) % 4)&0xFF + 1;//声调一声为1，无声调为0,^为5
					py_shengdiao <<= 8;
					py |= py_shengdiao;
					return MakeU32(CT_GB_HZ_PINYIN, py);
				}
				// ü ê ɑ  ń ň ǹ			ɡ
				switch (ch)
				{
				case 0xA8B9://ü
				{
					return MakeU32(CT_GB_HZ_PINYIN, 'v');//ü无声调
					break;
				}
				case 0xA8BA://ê
				{
					return MakeU32(CT_GB_HZ_PINYIN, 0x0500 | 'e');//ê
					break;
				}
				case 0xA8BB://ɑ
				{
					return MakeU32(CT_GB_HZ_PINYIN, 'a');//ɑ
					break;
				}
				case 0xA8BC://
				{
					return MakeU32(CT_GB_HZ_PINYIN, 0x200|'m');
					break;
				}
				case 0xA8BD://ń
				{
					return MakeU32(CT_GB_HZ_PINYIN, 0x200 | 'm');
					break;
				}
				case 0xA8BE://ň 
				{
					return MakeU32(CT_GB_HZ_PINYIN, 0x300 | 'm');
					break;
				}
				case 0xA8BF:// ǹ
				{
					return MakeU32(CT_GB_HZ_PINYIN, 0x400 | 'm');
					break;
				}
				case 0xA8C0://ɡ
				{
					return MakeU32(CT_GB_HZ_PINYIN, 'g');
					break;
				}
				}
				return 0;
			}
			SKIP_CODE_SECTION_LESS(0xA8C5);
			//CT_GB_HZ_ZHUYIN			= 0x8118,//注音：A8C5-A8E9
			if (ch <= 0xA8E9)
			{
				return MakeU32(CT_GB_HZ_ZHUYIN, ch);
			}
			SKIP_CODE_SECTION_LESS(0xA940);
			//CT_GB_PUNCT_3			= 0x8119,//标点与符号4：A940-A96E（~-杭州数字九）a949（带全正）（a94a单位：mg,kg,mm,cm,km,m2,ccKM,ln,log,mil,）（A959TEL）（A95C连字符-）
			if (ch <= 0xA96E)
			{
				return MakeU32(CT_GB_PUNCT_UNTAG, ch);
			}
			//CT_GB_PUNCT_LITTLE		= 0x811A,//小型符号：A96F-A988（逗号，顿号，句号，分号，冒号，问号，感叹号，圆括号左右，花括号左右，方括号左右，#&*+-<>=\$%@）
			if (ch <= 0xA988)
			{//﹐﹑﹒﹔﹕﹖﹗﹙﹚﹛﹜﹝﹞﹟﹠﹡ ﹢﹣﹤﹥﹦﹨﹩﹪﹫
				switch (ch)
				{
				case 0xA96F:
					return MakeU32(CT_GB_PUNCT, PT_Comma);
					break;
				case 0xA970:
					return MakeU32(CT_GB_PUNCT, PT_Pause);
					break;
				case 0xA971:
					return MakeU32(CT_GB_PUNCT, PT_Period);
					break;
				case 0xA972:
					return MakeU32(CT_GB_PUNCT, PT_Semicolon);
					break;
				case 0xA973:
					return MakeU32(CT_GB_PUNCT, PT_Colon);
					break;
				case 0xA974:
					return MakeU32(CT_GB_PUNCT, PT_Question);
					break;
				case 0xA975:
					return MakeU32(CT_GB_PUNCT, PT_Exclamation);
					break;
				case 0xA976:
				{
					PairPunctuationInfo pair(PT_Parentheses, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA977:
				{
					PairPunctuationInfo pair(PT_Parentheses, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA978:
				{
					PairPunctuationInfo pair(PT_Brace, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA979:
				{
					PairPunctuationInfo pair(PT_Brace, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA97A:
				{
					PairPunctuationInfo pair(PT_ShellBrackets, true, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA97B:
				{
					PairPunctuationInfo pair(PT_ShellBrackets, false, true);
					return MakeU32(CT_GB_PUNCT, pair.GetTypeDetail());
					break;
				}
				case 0xA97C:
				{
					return MakeU32(CT_GB_PUNCT, PT_NUM);
				}
				case 0xA97D:
				{
					return MakeU32(CT_GB_PUNCT, PT_AND);
				}
				case 0xA97E:
				{
					return MakeU32(CT_GB_PUNCT, PT_STAR);
				}
				//﹢﹣﹤﹥﹦﹨﹩﹪﹫〾
				case 0xA980:
				{
					return MakeU32(CT_GB_PUNCT, PT_PLUS);
				}
				case 0xA981:
				{
					return MakeU32(CT_GB_PUNCT, PT_MINUS);
				}
				case 0xA982:
				{
					return MakeU32(CT_GB_PUNCT, PT_LT);
				}
				case 0xA983:
				{
					return MakeU32(CT_GB_PUNCT, PT_GT);
				}
				case 0xA984:
				{
					return MakeU32(CT_GB_PUNCT, PT_EQ);
				}
				case 0xA985:
				{
					return MakeU32(CT_GB_PUNCT, PT_Backlash);
				}
				case 0xA986:
				{
					return MakeU32(CT_GB_PUNCT, PT_Dollar);
				}
				case 0xA987:
				{
					return MakeU32(CT_GB_PUNCT, PT_Percentage);
				}
				case 0xA988:
				{
					return MakeU32(CT_GB_PUNCT, PT_AT);
				}
				}
				return MakeU32(CT_GB_PUNCT_UNTAG,ch);
			}
			//CT_GB_HZ_LING			= 0x811B,//汉字数字〇：A996
			if (ch == 0xA996)
			{
				return MakeU32(CT_HANZI_LING, 0);
			}
			SKIP_CODE_SECTION_LESS(0xA9A4);
			//CT_GB_PUNCT_TAB_1		= 0x811C,//制表符2：A9A4-A9EF
			if (ch <= 0xA9EF)
			{
				return MakeU32(CT_GB_PUNCT_TAB, ch);
			}
		}
		else if (ch >= 0xAA40 && ch <= 0xFEA0)
		{
			unsigned short word_index = GB2312_GetIndex(ch);
			if (word_index != 0)
			{
				return MakeU32(CT_HANZI_GB,word_index);
			}
			return MakeU32(CT_HANZI_CJK,ch);
		}
		return CT_NONE;
	}
	
}//end of namespace Hanzi;


#endif // !GBK_TAG_H_
