/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: PNSLogger.c
 *  
 * Class Information:
 *
 * Class handles logging info
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 16/10/2022 - Initial Code Development
 */

class PNSLogger extends PluginBase {
	private ref array<string> filePaths;
	private const ref array<string> subDirectories = { "Access", "Admin", "Debug" };
	private const string logFolderDir = PNSConstants.configRoot + "\\logs";
	private const string fileType = ".log";
	private int year, month, day, hour, minute, second;

	void PNSLogger() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		filePaths = new array<string>();

		if (!FileExist(PNSConstants.configRoot )) {
			MakeDirectory(PNSConstants.configRoot);
		}

		if (!FileExist(logFolderDir)) {
			MakeDirectory(logFolderDir);
		}
		CheckAndCreateSubDirectories();
	}

	private void CheckAndCreateSubDirectories() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);

		for (int i = 0; i < subDirectories.Count(); i++) {
			string subDirectory = subDirectories[i];
			string directory = logFolderDir + subDirectory;
			if (!FileExist(directory)) {
				MakeDirectory(directory);
			}
			if (!CheckExistingFile(directory, subDirectory)) {
				CreateNewLogFile(directory, subDirectory);
			}
		}
	}

	private bool CheckExistingFile(string directory, string subDirectory) {
		FindFileHandle findFileHandler;
		string filePattern, fileName, dateFormat, dateTimeFormat;
		int fileAttr, flags;

		dateFormat = "[" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + "-" + year.ToStringLen(2) + "]";
		dateTimeFormat = dateFormat + "[" + hour.ToStringLen(2) + "." + minute.ToStringLen(2) + "." + second.ToStringLen(2) + "]";
		filePattern =  directory + "\\" + dateFormat + "*" + fileType;
		findFileHandler = FindFile(filePattern, fileName, fileAttr, flags);

		if (fileName != string.Empty) {
			string logDir = directory + "\\" + fileName;
			FileHandle logFile = OpenFile(logDir, FileMode.APPEND);

			filePaths.Insert(logDir);
			
			FPrintln(logFile, dateTimeFormat + " Log file reloaded ( Server Restart )");
			CloseFile(logFile);
			return true;
		}
		return false;
	}

	private void CreateNewLogFile(string directory, string subDirectory) {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		string dateTimeFormat = "[" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + "-" + year.ToStringLen(2) + "]" + "[" + hour.ToStringLen(2) + "." + minute.ToStringLen(2) + "." + second.ToStringLen(2) + "]";
		string logFileName = dateTimeFormat + " " + subDirectory + fileType;
		string creationText = dateTimeFormat + " New " + subDirectory + " Log File Created!";
		string logDir = directory + "\\" + logFileName;

		filePaths.Insert(logDir);
		FileHandle logFile = OpenFile(logDir, FileMode.WRITE);
		FPrintln(logFile, creationText);
		CloseFile(logFile);
	}

	void WriteLog(string type, PlayerIdentity playerId = null, vector pos = "0 0 0", string accessType = "", bool claim = false, bool cut = false, float damage = 0, float health = 0) {
			if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
	
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			string timeFormat = "[" + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2) + "]";
			string startText = "Player (" + playerId.GetName() + ", " + playerId.GetPlainId() + ")";
			string logDir;
			string logText;
	
			type.ToLower();
			switch (type) {
				case "Debug":
					{
						startText = "[PNS - LogHandler] :: [DEBUG] :: (" + ")";
						logDir = filePaths[4];
						accessType.ToLower();
	
						switch (accessType) {
							case "join":
								{
									logText = startText + " joined the server!";
									break;
								}
							default:
								{
									logText = startText + "(" + pos + ")" + " used admin on a storage container!!";
									break;
								}
						}
						break;
					}
			}
			FileHandle logFile = OpenFile(logDir, FileMode.APPEND);
			FPrintln(logFile, timeFormat + " " + logText);
			CloseFile(logFile);
	}

	void WriteDebug(string errMSG) {
			if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
	
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			string timeFormat = "[" + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2) + "]";
			string startText = "[PNS - LogHandler] :: [DEBUG] :: ";
			string logDir;
			string logText;

			logDir = filePaths[4];
			Print(startText); 
			logText = startText + errMSG;
			FileHandle logFile = OpenFile(logDir, FileMode.APPEND);
			FPrintln(logFile, timeFormat + " " + logText);
			CloseFile(logFile);
	}	
	
PNSLogger GetPNSLogger() {
	if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }
	return PNSLogger.Cast(GetPlugin(PNSLogger));
}
}