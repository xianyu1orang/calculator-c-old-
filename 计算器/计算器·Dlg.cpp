// 计算器·Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "计算器·.h"
#include "计算器·Dlg.h"
#include "math.h"

#define yes_length 10
#define length 100
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool zhong = 0;
bool gao = 0;
CString m_huanyuan[length];
int zhi = 0;
bool guanliyuan = 0;
bool gly = 0;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_num = _T("请输入");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_num);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_jieguo, Onjieguo)
	ON_BN_CLICKED(IDC_chehui, Onchehui)
	ON_BN_CLICKED(IDC_0, On0)
	ON_BN_CLICKED(IDC_1, On1)
	ON_BN_CLICKED(IDC_2, On2)
	ON_BN_CLICKED(IDC_3, On3)
	ON_BN_CLICKED(IDC_4, On4)
	ON_BN_CLICKED(IDC_5, On5)
	ON_BN_CLICKED(IDC_6, On6)
	ON_BN_CLICKED(IDC_7, On7)
	ON_BN_CLICKED(IDC_8, On8)
	ON_BN_CLICKED(IDC_9, On9)
	ON_BN_CLICKED(IDC_dian, Ondian)
	ON_BN_CLICKED(IDC_AC, OnAc)
	ON_BN_CLICKED(IDC_CE, OnCe)
	ON_BN_CLICKED(IDC_jia, Onjia)
	ON_BN_CLICKED(IDC_jian, Onjian)
	ON_BN_CLICKED(IDC_cheng, Oncheng)
	ON_BN_CLICKED(IDC_chu, Onchu)
	ON_BN_CLICKED(IDC_mo, Onmo)
	ON_BN_CLICKED(IDC_qufan, Onqufan)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_help, Onhelp)
	ON_BN_CLICKED(IDC_mi, Onmi)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_E, OnE)
	ON_BN_CLICKED(IDC_PI, OnPi)
	ON_BN_CLICKED(IDC_huanyuan, Onhuanyuan)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_1x, On1x)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(false);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
	pBtn->SetCheck(1);OnCheck2();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int y(char ch[]){
	int i = 0;
	while(ch[i] != '\0'){
		i ++;
	}
	return i + 1;
}

void CMyDlg::Onjieguo() 
{
	// TODO: Add your control notification handler code here
	/*if(zhong) UpdateData(true);

	bool yes[yes_length] = {1,1,1,1,1,1,1,1,1,1};
	int yes2[yes_length] = {IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES};
	bool yes3 = 1;

	char ch[150];
	memset(ch, 0, 150);
	memcpy(ch, m_num, m_num.GetLength());

	int fuhao = 0;
	for(int y_a = 0;y_a < y(ch);y_a ++){//负号？
		if(ch[y_a] == '%' || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a + 1] == '-'){
				fuhao = MessageBox("您的式子疑似使用减号做负号的样子，是否替换成~？","询问",MB_YESNO);
				if(fuhao == IDYES){
					if(ch[0] == '-') ch[0] = '~';
					for(int y_b = 0;y_b < y(ch);y_b ++){
						if(ch[y_b] == '%' || ch[y_b] == '*' || ch[y_b] == '/' || ch[y_b] == '+' || ch[y_b] == '-'){
							if(ch[y_b + 1] == '-') ch[y_b + 1] = '~'; m_num = ch;
						}
					}
				}
				break;
			}
		}
	}

	if(m_num == "") yes[0] = 0;//表达式为空

	for(int o = 0; o < y(ch); o++){//小数后错误
		if(ch[o] == '.' && !(ch[o + 1] >= '0' && ch[o + 1] <= '9')) yes[2] = 0;
	}

	for(int x = 0;x < y(ch);x ++){//小数取模
		if(ch[x] == '.'){
			for(int w = 0;w < 100;w ++){
				if(ch[w] == '%') yes[1] = 0;
				else if(ch[w] == '+' || ch[w] == '-' || ch[w] == '*' || ch[w] == '/' || ch[w] == '^' && gao) break;
			}
		}
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//没有符号
		if(ch[y_a] == '%' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-' || ch[y_a] == '^' && gao) break;
		else if(ch[y_a] != '%' && ch[y_a] != '*' && ch[y_a] != '/' && ch[y_a] != '+' && ch[y_a] != '-' && ch[y_a] != '^' && y_a == 99)
		yes[3] = 0;
	}

	for(int y_b = 0;y_b < y(ch);y_b ++){//异常符号
		if(!(ch[y_b] == '^' && gao ||ch[y_b] == '%' && gao || ch[y_b] == '^' || ch[y_b] == '*' || ch[y_b] == '/' || ch[y_b] == '+' || ch[y_b] == '-' || ch[y_b] == '.' || ch[y_b] == '~' || ch[y_b] >= '0' && ch[y_b] <= '9') && ch[y_b] != 0) yes[4] = 0;
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//符号后错误
		if(ch[y_a] == '%' && gao || ch[y_a] == '^' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a + 1] == 0 || ch[y_a + 1] == '~' && ch[y_a + 2] == 0 || (ch[y_a + 1] == '%' || ch[y_a + 1] == '*' || ch[y_a + 1] == '/' || ch[y_a + 1] == '+' || ch[y_a + 1] == '-'|| ch[y_a + 1] == '^' && gao)) yes[5] = 0;
		}
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//除数为0
		if(ch[y_a] == '/'){
			if(ch[y_a + 1] == '0' || ch[y_a + 2] == '0') yes[6] = 0;
		}
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//符号前错误
		if(ch[y_a] == '%' || ch[y_a] == '^' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a - 1] == '~' || ch[y_a - 1] == 0) yes[7] = 0;
		}
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//负号前错误
		if(ch[y_a] == '~'){
			if(ch[y_a - 1] >= '0' && ch[y_a - 1] <= '9') 
				yes[8] = 0;
		}
	}

	for(y_a = 0;y_a < y(ch);y_a ++){//含有高级符号
		if(ch[y_a] == '^' && !gao || ch[y_a] == '%' && ! gao ){
				yes[9] = 0;
		}
	}

	if(!yes[0]){
		yes2[0] = MessageBox("表达式为空！是否继续？","询问",MB_YESNO);
		if(yes2[0] == IDNO) yes3 = 0;
	}
	
	else if(fuhao){}

	else if(!yes[1]){
		yes2[1] = MessageBox("小数不取模！是否继续？","询问",MB_YESNO);
		if(yes2[1] == IDNO) yes3 = 0;
	}

	else if(!yes[2]){
		yes2[2] = MessageBox("小数后错误！是否继续？","询问",MB_YESNO);
		if(yes2[2] == IDNO) yes3 = 0;
	}

	else if(!yes[3]){
		yes2[3] = MessageBox("没有计算符号！是否继续？","询问",MB_YESNO);
		if(yes2[3] == IDNO) yes3 = 0;
	}

	else if(!yes[4]){
		yes2[4] = MessageBox("含有异常符号！是否继续？","询问",MB_YESNO);
		if(yes2[4] == IDNO) yes3 = 0;
	}

	else if(!yes[5]){
		yes2[5] = MessageBox("符号后错误！是否继续？","询问",MB_YESNO);
		if(yes2[5] == IDNO) yes3 = 0;
	}

	else if(!yes[6]){
		yes2[6] = MessageBox("除数不能为0！是否继续？","询问",MB_YESNO);
		if(yes2[6] == IDNO) yes3 = 0;
	}

	else if(!yes[7]){
		yes2[7] = MessageBox("符号前错误！是否继续？","询问",MB_YESNO);
		if(yes2[7] == IDNO) yes3 = 0;
	}
	
	else if(!yes[8]){
		yes2[8] = MessageBox("负号错误！是否继续？","询问",MB_YESNO);
		if(yes2[8] == IDNO) yes3 = 0;
	}

	else if(!yes[9]){
		yes2[9] = MessageBox("含有高级符号却没启用高级选项！是否继续？","询问",MB_YESNO);
		if(yes2[9] == IDNO) yes3 = 0;
	}

	if(yes3){
		
			m_huanyuan[zhi] = m_num;zhi ++;

			char ch[150];
			char str[150];
			char str2[150];

			int number = 0;
			int number2 = 0;
			int number3 = 1;

			double num[100];
			memset(ch, 0, 150);
			memcpy(ch, m_num, m_num.GetLength());

			for(int a = 0;a < 100;a ++){
				if(ch[a] >= '0' && ch[a] <= '9' || ch[a] == '.' || ch[a] == '~'){
					str[number] = ch[a];
					number ++;
				}
				else if(ch[a] != 0){
					str2[number2] = ch[a];
					if(str[0] == '~'){
						for(int r = 0;r < 20;r ++) str[r] = str[r + 1];
						num[number2] = atof(str);
						num[number2] = num[number2] - num[number2] * 2;
					}
					else num[number2] = atof(str);
					number = 0;number2 ++;
				}
				else if(ch[a] == 0){
					str[number] = 0;
				}
			}

			num[number2] = atof(str);
			if(str[0] == '~'){
				for(int r = 0;r < 20;r ++) str[r] = str[r + 1];
				num[number2] = atof(str);
				num[number2] = num[number2] - num[number2] * 2;
			}

			for(int c = number2 + 1;c < 50;c ++){
				str2[c] = 0;
			}
			
			int z = 0;int question = 0;
			question = MessageBox("是否优先级计算？","Please Select!",MB_YESNOCANCEL);

			
			int num_i[150];
			int num_d[150];
			
			//sprintf(str,"%lf %lf",num_d[0],num_d[1]);m_num = str;

			if(question == IDNO && question != IDCANCEL){

				for(z = 0;z < y(ch);z ++){

					if(str2[z] == '%' && gao || str2[z] == '*' || str2[z] == '/' || str2[z] == '+' || str2[z] == '-' || str2[z] == '^' && gao){

					for(int z_a = z;z_a < y(ch);z_a ++){
						num_i[z_a] = num[z_a];
					}
	
					for(z_a = z;z_a < y(ch);z_a ++){
						num_d[z_a] = num[z_a] - num_i[z_a];
					}

					if(str2[z] == '%'){
						int num_i1 = num[z];
						int num_i2 = num[z + 1];
					
						num[z] = double(num_i1 % num_i2);
					}

					else if(str2[z] == '*' ){
						num_i[z] = num_i[z] * (num_i[z + 1] + num_d[z + 1]);
						num_d[z] = num_d[z] * (num_i[z + 1] + num_d[z + 1]);
						num[z] = num_i[z] + num_d[z];
					}
					
					else if( str2[z] == '/' ){
						num_i[z] = num_i[z] / (num_i[z + 1] + num_d[z + 1]);
						num_d[z] = num_d[z] / (num_i[z + 1] + num_d[z + 1]);
						num[z] = num_i[z] + num_d[z];
					}

					else if(str2[z] == '+'){
						num_i[z] = num_i[z] + num_i[z + 1];
						num_d[z] = num_d[z] + 1;
						
						num[z] = num_i[z] + num_d[z];
						sprintf(str,"%lf",num_d[0]);m_num = str;
					}
					else if(str2[z] == '-' ){
						num_i[z] = num_i[z] - num_i[z + 1];
						num_d[z] = num_d[z] - num_d[z + 1];
						num[z] = num_i[z] + num_d[z];
					}
					else if( str2[z] == '^' ){
						num_i[z] = pow(num_i[z],(num_i[z + 1] + num_d[z + 1]));
						num_d[z] = pow(num_d[z],(num_i[z + 1] + num_d[z + 1]));
						num[z] = num_i[z] + num_d[z];
					}

					for(int y = z + 1;y < 100;y ++){
							num[y] = num[y + 1];
							str2[y - 1] = str2[y];
						}
					z --;
					}
					else if(str2[z] == 0) break;
					}
				
			}
			else if(question == IDYES && question != IDCANCEL){

			for(int b = 0;b < 50;b ++){
				
				if(str2[b] == '*' || str2[b] == '/' || str2[b] == '%' && gao || str2[b] == '^' && gao){
					
					for(int z_a = z;z_a < y(ch);z_a ++){
						num_i[z_a] = num[z_a];
					}
	
					for(z_a = z;z_a < y(ch);z_a ++){
						num_d[z_a] = num[z_a] - num_i[z_a];
					}

					if( str2[b] == '*' ){
						num_i[z] = num_i[z] * (num_i[z + 1] + num_d[z + 1]);
						num_d[z] = num_d[z] * (num_i[z + 1] + num_d[z + 1]);
						num[z] = num_i[z] + num_d[z];
					}
					else if( str2[b] == '/' ){
						num_i[z] = num_i[z] / (num_i[z + 1] + num_d[z + 1]);
						num_d[z] = num_d[z] / (num_i[z + 1] + num_d[z + 1]);
						num[z] = num_i[z] + num_d[z];
					}
					else if(str2[b] == '%'){
						int num_i1 = num[b];
						int num_i2 = num[b + 1];
					
						num[b] = double(num_i1 % num_i2);
					}
					else if( str2[b] == '^' ){
						num_i[z] = pow(num_i[z],(num_i[z + 1] + num_d[z + 1]));
						num_d[z] = pow(num_d[z],(num_i[z + 1] + num_d[z + 1]));
						num[z] = num_i[z] + num_d[z];
					}

					for(int c = b + 1;c < 100;c ++){
						num[c] = num[c + 1];
						str2[c - 1] = str2[c];
					}
					b --;
				}
				else if(str2[b] == 0) break;
			}

			for(int f = 0;f < 50;f ++){
				if(str2[f] == '+' || str2[f] == '-'){

					for(int z_a = z;z_a < y(ch);z_a ++){
						num_i[z_a] = num[z_a];
					}
	
					for(z_a = z;z_a < y(ch);z_a ++){
						num_d[z_a] = num[z_a] - num_i[z_a];
					}

					if(str2[f] == '+'){
						num_i[z] = num_i[z] + num_i[z + 1];
						num_d[z] = num_d[z] + num_d[z + 1];
						num[z] = num_i[z] + num_d[z];
					}
					else if( str2[f] == '-' ){
						num_i[z] = num_i[z] - num_i[z + 1];
						num_d[z] = num_d[z] - num_d[z + 1];
						num[z] = num_i[z] + num_d[z];
					}

					str2[f] = 0;
					for(int g = f + 1;g < 100;g ++){
						num[g] = num[g + 1];
						str2[g - 1] = str2[g];
					}
					f --;
				}
				else if(str2[f] == 0) break;
			}

			}
			//sprintf(str,"%lf",num[0]);m_num = str;

			for(int d = 0;d < 100;d ++){
				if(str[d] == '0'){
					for(int f = d + 1;f < 10;f ++){
						if(str[f] != '0'){
							break;
						}
						else if(str[f + 1] == 0){
							for(int g = d;g < 10;g ++)
							str[g] = 0;
						}
					}
				}
			}
			
			for(int e = 0; e < 20;e ++){
				if(str[e] == '.' && str[e + 1] == 0)
				str[e] = 0;
			}

			for(e = 0; e < 20;e ++){
				if(str[e] == '-')
				str[e] = '~';
			}

			//if(question != IDCANCEL) m_num = str;
	}*/
	
	if(zhong) UpdateData(true);

	bool yes[yes_length] = {1,1,1,1,1,1,1,1,1,1};
	int yes2[yes_length] = {IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES,IDYES};
	bool yes3 = 1;

	char ch[100];
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	int fuhao = 0;
	for(int y_a = 0;y_a < 100;y_a ++){//负号？
		if(ch[y_a] == '%' || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a + 1] == '-'){
				fuhao = MessageBox("您的式子疑似使用减号做负号的样子，是否替换成~？","询问",MB_YESNO);
				if(fuhao == IDYES){
					if(ch[0] == '-') ch[0] = '~';
					for(int y_b = 0;y_b < 100;y_b ++){
						if(ch[y_b] == '%' || ch[y_b] == '*' || ch[y_b] == '/' || ch[y_b] == '+' || ch[y_b] == '-'){
							if(ch[y_b + 1] == '-') ch[y_b + 1] = '~'; m_num = ch;
						}
					}
				}
				break;
			}
		}
	}

	if(m_num == "") yes[0] = 0;//表达式为空

	for(int o = 0; o < 100; o++){//小数后错误
		if(ch[o] == '.' && !(ch[o + 1] >= '0' && ch[o + 1] <= '9')) yes[2] = 0;
	}

	for(int x = 0;x < 100;x ++){//小数取模
		if(ch[x] == '.'){
			for(int w = 0;w < 100;w ++){
				if(ch[w] == '%') yes[1] = 0;
				else if(ch[w] == '+' || ch[w] == '-' || ch[w] == '*' || ch[w] == '/' || ch[w] == '^' && gao) break;
			}
		}
	}

	for(y_a = 0;y_a < 100;y_a ++){//没有符号
		if(ch[y_a] == '%' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-' || ch[y_a] == '^' && gao) break;
		else if(ch[y_a] != '%' && ch[y_a] != '*' && ch[y_a] != '/' && ch[y_a] != '+' && ch[y_a] != '-' && ch[y_a] != '^' && y_a == 99)
		yes[3] = 0;
	}

	for(int y_b = 0;y_b < 100;y_b ++){//异常符号
		if(!(ch[y_b] == '^' && gao ||ch[y_b] == '%' && gao || ch[y_b] == '^' || ch[y_b] == '*' || ch[y_b] == '/' || ch[y_b] == '+' || ch[y_b] == '-' || ch[y_b] == '.' || ch[y_b] == '~' || ch[y_b] >= '0' && ch[y_b] <= '9') && ch[y_b] != 0) yes[4] = 0;
	}

	for(y_a = 0;y_a < 100;y_a ++){//符号后错误
		if(ch[y_a] == '%' && gao || ch[y_a] == '^' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a + 1] == 0 || ch[y_a + 1] == '~' && ch[y_a + 2] == 0 || (ch[y_a + 1] == '%' || ch[y_a + 1] == '*' || ch[y_a + 1] == '/' || ch[y_a + 1] == '+' || ch[y_a + 1] == '-'|| ch[y_a + 1] == '^' && gao)) yes[5] = 0;
		}
	}

	for(y_a = 0;y_a < 100;y_a ++){//除数为0
		if(ch[y_a] == '/'){
			if(ch[y_a + 1] == '0' || ch[y_a + 2] == '0') yes[6] = 0;
		}
	}

	for(y_a = 0;y_a < 100;y_a ++){//符号前错误
		if(ch[y_a] == '%' || ch[y_a] == '^' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-'){
			if(ch[y_a - 1] == '~' || ch[y_a - 1] == 0) yes[7] = 0;
		}
	}

	for(y_a = 0;y_a < 100;y_a ++){//负号前错误
		if(ch[y_a] == '~'){
			if(ch[y_a - 1] >= '0' && ch[y_a - 1] <= '9') 
				yes[8] = 0;
		}
	}

	for(y_a = 0;y_a < 100;y_a ++){//含有高级符号
		if(ch[y_a] == '^' && !gao || ch[y_a] == '%' && !gao ){
				yes[9] = 0;
		}
	}

	if(!yes[0]){
		yes2[0] = MessageBox("表达式为空！是否继续？","询问",MB_YESNO);
		if(yes2[0] == IDNO) yes3 = 0;
	}
	
	else if(fuhao){}

	else if(!yes[1]){
		yes2[1] = MessageBox("小数不取模！是否继续？","询问",MB_YESNO);
		if(yes2[1] == IDNO) yes3 = 0;
	}

	else if(!yes[2]){
		yes2[2] = MessageBox("小数后错误！是否继续？","询问",MB_YESNO);
		if(yes2[2] == IDNO) yes3 = 0;
	}

	else if(!yes[3]){
		yes2[3] = MessageBox("没有计算符号！是否继续？","询问",MB_YESNO);
		if(yes2[3] == IDNO) yes3 = 0;
	}

	else if(!yes[4]){
		yes2[4] = MessageBox("含有异常符号！是否继续？","询问",MB_YESNO);
		if(yes2[4] == IDNO) yes3 = 0;
	}

	else if(!yes[5]){
		yes2[5] = MessageBox("符号后错误！是否继续？","询问",MB_YESNO);
		if(yes2[5] == IDNO) yes3 = 0;
	}

	else if(!yes[6]){
		yes2[6] = MessageBox("除数不能为0！是否继续？","询问",MB_YESNO);
		if(yes2[6] == IDNO) yes3 = 0;
	}

	else if(!yes[7]){
		yes2[7] = MessageBox("符号前错误！是否继续？","询问",MB_YESNO);
		if(yes2[7] == IDNO) yes3 = 0;
	}
	
	else if(!yes[8]){
		yes2[8] = MessageBox("负号错误！是否继续？","询问",MB_YESNO);
		if(yes2[8] == IDNO) yes3 = 0;
	}

	else if(!yes[9]){
		yes2[9] = MessageBox("含有高级符号却没启用高级选项！是否继续？","询问",MB_YESNO);
		if(yes2[9] == IDNO) yes3 = 0;
	}

	if(yes3){
		
			m_huanyuan[zhi] = m_num;zhi ++;
			char ch[100];
			char str[100];
			char str2[50];

			int number = 0;
			int number2 = 0;
			int number3 = 1;

			double num[100];
			memset(ch, 0, 100);
			memcpy(ch, m_num, m_num.GetLength());

			for(int a = 0;a < 100;a ++){
				if(ch[a] >= '0' && ch[a] <= '9' || ch[a] == '.' || ch[a] == '~'){
					str[number] = ch[a];
					number ++;
				}
				else if(ch[a] != 0){
					str2[number2] = ch[a];
					if(str[0] == '~'){
						for(int r = 0;r < 20;r ++) str[r] = str[r + 1];
						num[number2] = atof(str);
						num[number2] = num[number2] - num[number2] * 2;
					}
					else num[number2] = atof(str);
					number = 0;number2 ++;
				}
				else if(ch[a] == 0){
					str[number] = 0;
				}
			}

			num[number2] = atof(str);
			if(str[0] == '~'){
				for(int r = 0;r < 20;r ++) str[r] = str[r + 1];
				num[number2] = atof(str);
				num[number2] = num[number2] - num[number2] * 2;
			}

			for(int c = number2 + 1;c < 50;c ++){
				str2[c] = 0;
			}
			
			int z = 0;int question = 0;
			question = MessageBox("是否优先级计算？","Please Select!",MB_YESNOCANCEL);

			if(question == IDNO && question != IDCANCEL){

				for(;z < 50;z ++){

					if(str2[z] == '%' && gao || str2[z] == '*' || str2[z] == '/' || str2[z] == '+' || str2[z] == '-' || str2[z] == '^' && gao){

					if(str2[z] == '%'){
						int num_i1 = num[z];
						int num_i2 = num[z + 1];
					
						num[z] = double(num_i1 % num_i2);
					}
					else if(str2[z] == '*' )
					num[z] = num[z] * num[z + 1];
					else if( str2[z] == '/' )
					num[z] = num[z] / num[z + 1];
					else if(str2[z] == '+')
					num[z] = num[z] + num[z + 1];
					else if(str2[z] == '-' )
					num[z] = num[z] - num[z + 1];
					else if( str2[z] == '^' )
					num[z] = pow(num[z],num[z + 1]);

					for(int y = z + 1;y < 100;y ++){
							num[y] = num[y + 1];
							str2[y - 1] = str2[y];
						}
					z --;
					}
					else if(str2[z] == 0) break;
					}

			}
			else if(question == IDYES && question != IDCANCEL){

			for(int b = 0;b < 50;b ++){
				
				if(str2[b] == '*' || str2[b] == '/' || str2[b] == '%' && gao || str2[b] == '^' && gao){
					if( str2[b] == '*' )
					num[b] = num[b] * num[b + 1];
					else if( str2[b] == '/' )
					num[b] = num[b] / num[b + 1];
					else if(str2[b] == '%'){
						int num_i1 = num[b];
						int num_i2 = num[b + 1];
					
						num[b] = double(num_i1 % num_i2);
					}
					else if( str2[b] == '^' ){
						num[b] = pow(num[b],num[b + 1]);
					}

					for(int c = b + 1;c < 100;c ++){
						num[c] = num[c + 1];
						str2[c - 1] = str2[c];
					}
					b --;
				}
				else if(str2[b] == 0) break;
			}

			for(int f = 0;f < 50;f ++){
				if(str2[f] == '+' || str2[f] == '-'){
					if(str2[f] == '+')
					num[f] = num[f] + num[f + 1];
					else if( str2[f] == '-' )
					num[f] = num[f] - num[f + 1];

					str2[f] = 0;
					for(int g = f + 1;g < 100;g ++){
						num[g] = num[g + 1];
						str2[g - 1] = str2[g];
					}
					f --;
				}
				else if(str2[f] == 0) break;
			}

			}
			sprintf(str,"%lf",num[0]);

			for(int d = 0;d < 100;d ++){
				if(str[d] == '0'){
					for(int f = d + 1;f < 10;f ++){
						if(str[f] != '0'){
							break;
						}
						else if(str[f + 1] == 0){
							for(int g = d;g < 10;g ++)
							str[g] = 0;
						}
					}
				}
			}
			
			for(int e = 0; e < 20;e ++){
				if(str[e] == '.' && str[e + 1] == 0)
				str[e] = 0;
			}

			for(e = 0; e < 20;e ++){
				if(str[e] == '-')
				str[e] = '~';
			}

			if(question != IDCANCEL) m_num = str;
	}
	
	UpdateData(false);
}

void CMyDlg::Onchehui() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];int biao = 0;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i ++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' ||ch[i] == '/' || ch[i] == '%' && gao || ch[i] == '^' && gao ){
			biao = i;
		}
	}

	for(int p = biao + 1; p < 100;p ++){
		if(ch[p] >= '0' && ch[p] <= '9' || ch[p] >= '.') biao = p;
		else break;
	}

	ch[biao] = 0;
	m_num = ch;
	UpdateData(false);
}

void CMyDlg::On0() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(m_num == "0") yes = 0;
		if(ch[i] == '/' && ch[i + 1] == 0){
			yes = 0;
		}
	}
	
	if(!yes) MessageBox("不能添加0！");
	else if(yes) m_num += '0';
	UpdateData(false);
}

void CMyDlg::On1() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '1';
	UpdateData(false);
}

void CMyDlg::On2() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '2';
	UpdateData(false);
}

void CMyDlg::On3() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '3';
	UpdateData(false);
}

void CMyDlg::On4() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '4';
	UpdateData(false);
}

void CMyDlg::On5() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '5';
	UpdateData(false);
}

void CMyDlg::On6() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '6';
	UpdateData(false);
}

void CMyDlg::On7() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '7';
	UpdateData(false);
}

void CMyDlg::On8() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '8';
	UpdateData(false);
}

void CMyDlg::On9() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	m_num += '9';
	UpdateData(false);
}

void CMyDlg::Ondian() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;int can = 0;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao){
			if(ch[i + 1] == 0){
				yes = 0;
			}
		}
	}

	for(int p = 0; p < 100;p++){
		if(ch[p] == '.'){
			can = 1;
		}
		else if(can == 1 && ch[p] == '.') yes = 0;
		else if(can == 1){
			if(ch[p] == '+' || ch[p] == '-' || ch[p] == '*' || ch[p] == '/' || ch[p] == '%'  && gao || ch[p] == '^' && gao)
			can = 0;
		}
	}if(can == 1) yes = 0;
	
	if(!yes)  MessageBox("不能进行转换操作!");
	else if(m_num == "") MessageBox("不能进行转换操作!");
	else if(yes && !(m_num == "")) m_num += ".";

	UpdateData(false);
}

void CMyDlg::OnAc() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	for(int i = 0; i < 100;i++){
		Onchehui();
	}

	UpdateData(false);
}

void CMyDlg::OnCe() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());
	
	for(int p = 0;p < 100;p ++){
		if(ch[p] == '+' || ch[p] == '-' || ch[p] == '*' || ch[p] == '/' || ch[p] == '%'  && gao || ch[p] == '^' && gao ){
			for(int i = p + 1;i < 100;i ++){
				if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' ||ch[i] == '/' || ch[i] == '%' || ch[i] == '^') break;
				else if(ch[i] != '+' && ch[i] != '-' && ch[i] != '*' && ch[i] != '/' && ch[i] != '%'  && ch[i] != '^' && i == 99)
		
					for(int a = p + 1;a < 100;a ++) 
					ch[a] = 0;
			}
		}
	}
	for(p = 0;p < 100;p ++){
		if(ch[p] == '+' || ch[p] == '-' || ch[p] == '*' ||ch[p] == '/' || ch[p] == '%'  && gao || ch[p] == '^' && gao ) break;
		else if(ch[p] != '+' && ch[p] != '-' && ch[p] != '*' && ch[p] != '/' && ch[p] != '%'  && ch[p] != '^' && p == 99)
			for(int a = 0;a< 100;a ++) ch[a] = 0;
	}
	m_num = ch;
	UpdateData(false);
}

void CMyDlg::Onjia() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
			if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
				yes = 0;
			}
		}
	}
	
	for(int p = 0; p < 100;p++){
		if(ch[p] == '.'){
			if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
				yes = 0;
			}
		}
	}

	if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "+";
	UpdateData(false);
}

void CMyDlg::Onjian() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
			if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
				yes = 0;
			}
		}
	}
	
	for(int p = 0; p < 100;p++){
		if(ch[p] == '.'){
			if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
				yes = 0;
			}
		}
	}

	if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "-";
	UpdateData(false);
}

void CMyDlg::Oncheng() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
			if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
				yes = 0;
			}
		}
	}
	
	for(int p = 0; p < 100;p++){
		if(ch[p] == '.'){
			if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
				yes = 0;
			}
		}
	}

	if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "*";
	UpdateData(false);
}

void CMyDlg::Onchu() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	char ch[100];bool yes = 1;
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int i = 0; i < 100;i++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
			if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
				yes = 0;
			}
		}
	}
	
	for(int p = 0; p < 100;p++){
		if(ch[p] == '.'){
			if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
				yes = 0;
			}
		}
	}

	if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "/";
	UpdateData(false);
}

void CMyDlg::Onmo() 
{
	// TODO: Add your control notification handler code here
	if(gao){
		if(zhong) UpdateData(true);

		char ch[100];bool yes = 1;
		memset(ch, 0, 100);
		memcpy(ch, m_num, m_num.GetLength());

		for(int i = 0; i < 100;i++){
			if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
				if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
					yes = 0;
				}
			}
		}
	
		for(int p = 0; p < 100;p++){
			if(ch[p] == '.'){
				if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
					yes = 0;
				}
			}
		}

		if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "%";
		UpdateData(false);
	}
}

void CMyDlg::Onqufan() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	int biao = 0;
	bool boolean = 1;
	char ch[100];
	memset(ch, 0, 100);
	memcpy(ch, m_num, m_num.GetLength());

	for(int t = 0;t < 100;t ++){
		if(ch[t] == '-')
		ch[t] = '~';
	}

	for(t = 0;t < 100;t ++){
		if(ch[t] == '~'){
			for(int p = t + 1;p < 100;p ++){
				if(ch[p] == '~' || ch[p] == '*' || ch[p] == '/' ||  ch[p] == '%' || ch[p] == '+' || ch[p] == '-' && gao || ch[p] == '^' && gao ) break;
				else if(ch[p] != '~' && p == 99){
					for(int r = t;r < 100;r ++) ch[r] = ch[r + 1];boolean = 0;
				}
			}
		}
	}

	for(int i = 0;i < 100 && boolean == 1;i ++){
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
			for(int p = i + 1;p < 100;p ++){
				if(ch[p] == '+' || ch[p] == '-' || ch[p] == '*' ||ch[p] == '/' || ch[p] == '%'  && gao || ch[p] == '^' && gao ) break;
				else if(ch[p] != '+' && ch[p] != '-' && ch[p] != '*' && ch[p] != '/' && ch[p] != '%'  && ch[p] != '^' && p == 99 && ch[i + 1] != 0){
					for(int u = i + 1;u < 100;u ++){
						if(ch[u] != 0) biao = u;
					}
					for(int o = 100;o > i + 1;o --)
						ch[o] = ch[o - 1];
					ch[i + 1] = '~';
				}
			}
		}
	}

	for(int p = 0;p < 100 && boolean == 1;p ++){
		if(ch[p] == '+' || ch[p] == '-' || ch[p] == '*' ||ch[p] == '/' || ch[p] == '%'  && gao || ch[p] == '^' && gao ) break;
		else if(ch[p] != '+' && ch[p] != '-' && ch[p] != '*' && ch[p] != '/' && ch[p] != '%'  && ch[p] != '^' && p == 99 && m_num != ""){
			for(int u = 0;u < 100;u ++){
				if(ch[u] != 0) biao = u;
			}
			for(int o = 100;o > 0;o --)
				ch[o] = ch[o - 1];
			ch[0] = '~';
		}
	}

	m_num = ch;
	UpdateData(false);
}

void CMyDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	if(gao){
		if ( BST_CHECKED == IsDlgButtonChecked( IDC_CHECK1 ) )
		{
			zhong = 1;
		}
		else
		{
			zhong = 0;
			CString num = m_num;
			UpdateData(true);

			m_num = num;
			UpdateData(false);
		}
	}
	else{
		pBtn->SetCheck(0);
	}
}

void CMyDlg::Onhelp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_num == "3 23"){
		GetDlgItem(IDC_CHECK3)->ShowWindow(SW_SHOW);
		guanliyuan = 1;m_num = "";
	}

	if(guanliyuan) MessageBox("欢迎进入管理员模式！");
	else MessageBox("1.编辑的复选框的作用是使编辑框内输入的字符是否要代入式子中。\n不勾选默认为不进行编辑，勾选即可在编辑框内编辑。\n2.本程序默认~为负号。减号不能代替负号使用，但实际上计算时减号为负号只不过你看不到而已。\n3.本程序并不强制用~做负号，你可以使用编辑框输入数据绕过错误，他会询问你是否要替换。\n4.本程序提供优先级运算，即按运算顺序计算。\n5.使用高级键可以解锁更多功能，如果出现检查错误问题就有可能在这。\n6.还原键针对还原最近5个输入前式子，在编辑框里输入正整数判断式子。","帮助",MB_OK);
	UpdateData(false);
}

void CMyDlg::Onmi() 
{
	// TODO: Add your control notification handler code here
	if(gao){
		if(zhong) UpdateData(true);

		char ch[100];bool yes = 1;
		memset(ch, 0, 100);
		memcpy(ch, m_num, m_num.GetLength());

		for(int i = 0; i < 100;i++){
			if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%'  && gao || ch[i] == '^' && gao ){
				if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9') && ch[i + 1] != '~' || ch[i - 1] == '.' || (ch[i + 1] == '~' && ch[i + 2] == 0)){
					yes = 0;
				}
			}
		}
	
		for(int p = 0; p < 100;p++){
			if(ch[p] == '.'){
				if(!(ch[p + 1] >= '0' && ch[p + 1] <= '9') || !(ch[p - 1] >= '0' && ch[p - 1] <= '9')){
					yes = 0;
				}
			}
		}

		if(yes && m_num != "" && !(ch[0] == '~' && ch[1] == 0)) m_num += "^";
		UpdateData(false);
	}
}

void CMyDlg::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	if ( BST_CHECKED == IsDlgButtonChecked( IDC_CHECK2 ) )
	{
		gao = 1;

		GetDlgItem(IDC_mo)->EnableWindow(1);
		GetDlgItem(IDC_PI)->EnableWindow(1);
		GetDlgItem(IDC_E)->EnableWindow(1);
		GetDlgItem(IDC_huanyuan)->EnableWindow(1);
		GetDlgItem(IDC_CHECK1)->ShowWindow(SW_SHOW);

	}
	else
	{
		gao = 0;

		GetDlgItem(IDC_mo)->EnableWindow(FALSE);
		GetDlgItem(IDC_PI)->EnableWindow(FALSE);
		GetDlgItem(IDC_E)->EnableWindow(FALSE);
		GetDlgItem(IDC_huanyuan)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK1)->ShowWindow(SW_HIDE);

		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
		pBtn->SetCheck(0);
	}
}

void CMyDlg::OnE() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	
	OnCe();

	char ch[100];

	double num = 2.718281828459045;

	sprintf(ch,"%lf",num);

	m_num += ch;

	UpdateData(false);
}

void CMyDlg::OnPi() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	
	OnCe();

	char ch[100];

	double num = 3.1415926535898;

	sprintf(ch,"%lf",num);

	m_num += ch;

	UpdateData(false);
}

void CMyDlg::Onhuanyuan() 
{
	// TODO: Add your control notification handler code here]
	if(gao){

		if(zhong) UpdateData(true);

		int zhi_ = atoi(m_num);
		
		if(zhi_ > zhi || zhi_ < 1) MessageBox("检测错误！","error",MB_ICONHAND);

		else{
			int zhi_ = atoi(m_num);
			int yes = MessageBox("目前要还原信息为：" + m_huanyuan[zhi_ - 1]  + "\n编辑框是否输入确认？","还原",MB_YESNO);

			if(yes == IDYES)
			m_num = m_huanyuan[zhi_ - 1];

			UpdateData(false);
		}
	}
}

void CMyDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);

	if(m_num == "请输入") m_num = "";

	UpdateData(false);
}

void CMyDlg::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	if ( BST_CHECKED == IsDlgButtonChecked( IDC_CHECK3 ) )
	{
		gly = 1;
	}
	else
	{
		gly = 0;
	}
}

void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(zhi > 2)
	MessageBox("福利环节！本程序有管理员身份，在编辑框里输入3 23再看看点哪里喽");

	CDialog::OnOK();
}

void CMyDlg::On1x() 
{
	// TODO: Add your control notification handler code here
	if(zhong) UpdateData(true);
	
	OnCe();

	char ch[150];
	char ch_[150];
	memset(ch, 0, 150);
	memcpy(ch, m_num, m_num.GetLength());

	double num;
	int fuhao_zhi = 0;
	int number = 0;

	for(int y_a = 0;y_a < 150;y_a ++){
		if(ch[y_a] == '%' && gao || ch[y_a] == '*' || ch[y_a] == '/' || ch[y_a] == '+' || ch[y_a] == '-' || ch[y_a] == '^' && gao) fuhao_zhi = y_a;
		else if(ch[y_a] != '%' && ch[y_a] != '*' && ch[y_a] != '/' && ch[y_a] != '+' && ch[y_a] != '-' && ch[y_a] != '^' && y_a == 149){
			for(int a = 0;a < 150;a ++){
				if(ch[a] != '\0') fuhao_zhi = a;
			}
			MessageBox("p");
		}
	}
	
	for(int a = fuhao_zhi + 1;a < 150;a ++){
		if(ch[a] >= '0' && ch[a] <= '9' || ch[a] == '.' || ch[a] == '~'){
			if(ch[a] == '~') ch[a] = '-';
			ch_[number] = ch[a];
			number ++;
		}	
	}

	for(a = number;a < 151;a ++) ch_[a] = ' ';

	num = atof(ch_);

	sprintf(ch_,"%d",fuhao_zhi);

	m_num += ch_;

	UpdateData(false);
}
