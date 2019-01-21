//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef interfaceH
#define interfaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
#include "dynarray.h"
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnRun;
	TLabel *lblt;
	TLabel *Label1;
	TButton *btnCancel;
	TLabel *lblExeTime;
	TLabel *Label3;
	TLabel *Label2;
	TEdit *edtk;
	TLabel *Label4;
	TEdit *edtt_start;
	TLabel *Label5;
	TEdit *edtt_record;
	TLabel *Label6;
	TEdit *edtt_end;
	TLabel *Label7;
	TEdit *edtt_step;
	TLabel *Label8;
	TTimer *Timer1;
	TLabel *Label9;
	TEdit *edtlimiar;
	TLabel *Label10;
	TEdit *edtt_segment;
	TLabel *Label11;
	TEdit *edtSalExp;
	TImage *Image1;
	TCheckBox *cbLogging;
	TLabel *Label12;
	TEdit *edtDeltaOmega;
	TLabel *Label13;
	TLabel *lblSegObj;
	TLabel *lblSegmentationDone;
	TImage *ImageSegmented;
	TCheckBox *cbShifting;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *Label14;
	TEdit *edtSegSyncWindow;
	TLabel *Label15;
	TEdit *edtLogWindow;
	TButton *btnLoadImage;
	TLabel *lblSizeTxt;
	TLabel *lblSize;
	TButton *btnSetLogPixels;
	TLabel *Label16;
	TEdit *EditStopLoggingTime;
	TCheckBox *CheckBoxStopLoggingTime;
	TSavePictureDialog *SavePictureDialog1;
	TButton *ButtonSaveImage;
	TCheckBox *CheckBoxShowBehavior;
	void __fastcall btnRunClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall WCRunHandleTerminate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cbLoggingClick(TObject *Sender);
	void __fastcall btnLoadImageClick(TObject *Sender);
	void __fastcall btnSetLogPixelsClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CheckBoxStopLoggingTimeClick(TObject *Sender);
	void __fastcall ButtonSaveImageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	int **log_pixels;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
