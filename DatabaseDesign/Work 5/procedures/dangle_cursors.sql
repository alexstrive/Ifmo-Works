CREATE procedure DisplayDangleCursors as
  begin
    SELECT creation_time, cursor_id, name, c.session_id, login_name
    FROM sys.dm_exec_cursors(0) AS c
           JOIN sys.dm_exec_sessions AS s ON c.session_id = s.session_id
  end;